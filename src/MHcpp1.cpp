#include <Rcpp.h>
#include "Pi.h"
using namespace Rcpp;
//[[Rcpp::export]]
NumericMatrix MHcpp1(int B, double sd) {
  NumericMatrix R(B, 2);
  double x1 = 0.0, x2 = 0.0;
  for(int b = 1; b < B; b++) {
    double y1 = x1 + R::rnorm(0,sd);
    double y2 = x2 + R::rnorm(0,sd);
    double rho = Pi(y1, y2) / Pi(x1, x2);
    double u = R::unif_rand();
    if(u < rho) {
      x1 = y1;
      x2 = y2;
    }
    R(b,0) = x1;
    R(b,1) = x2;
  }
  return R;
} 

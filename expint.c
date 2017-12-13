#include <math.h>

double de1xb(double);
float fe1xb(float);
double deix(double);
float feix(float);

double de1xb(double x) {
  int maxit;
  double eps,euler,fpmin,fpmax;
  eps=6e-8;
  euler=.57721566;
  maxit=20;
  fpmin=1e-30;
  fpmax=1e30;
  int k;
  double sum,term;

  if (x == 0.0) return fpmax;
  if (x <= 1.) {
    sum = 1.;
    term = 1.;
    k=1;
    while ((fabs(term)>fabs(sum)*eps)&&(k<=maxit)){
      term = -term*k*x/( (k+1.)*(k+1.));
      sum = sum + term;
      k++;
    }
    return -euler - log(x) + x*sum;
  }

  term = 0.;
  for (k=maxit+(int)floor(80/x);k>=1;k--) {
    term = k/(1. + k/(x+term));
  }
  return exp(-x) / (x+term);
 }

float fe1xb(float x) {
  int maxit;
  float eps,euler,fpmin,fpmax;
  eps=6e-8;
  euler=.57721566;
  maxit=20;
  fpmin=1e-30;
  fpmax=1e30;
  int k;
  float sum,term;

  if (x == 0.0) return fpmax;
  if (x <= 1.) {
    sum = 1.;
    term = 1.;
    k=1;
    while ((fabs(term)>fabs(sum)*eps)&&(k<=maxit)){
      term = -term*k*x/( (k+1.)*(k+1.));
      sum = sum + term;
      k++;
    }
    return -euler - log(x) + x*sum;
  }

  term = 0.;
  for (k=maxit+(int)floor(80/x);k>=1;k--) {
    term = k/(1. + k/(x+term));
  }
  return exp(-x) / (x+term);
 }

double deix(double x) {
      int maxit;
      double eps,euler,fpmin,fpmax;
      eps=6e-8;
      euler=.57721566;
      maxit=100;
      fpmin=1e-30;
      fpmax=1e30;
      int k;
      double sum,term;
      if (x == 0.0) return -fpmax;

      if (x < 0.0) return -de1xb(-x);
      if (fabs(x) <= 40.) {
        // Power series around x=0

        sum = 1.0;
        term =1.0;
        k = 1;
        while ((fabs(term/sum) > eps)&&(k<=maxit)) {
          term = term*k*x/( (k+1.)*(k+1.));
          sum += term;
          k++;
        }
        return euler + log(x) + x*sum;
      }

      // Asymptotic expansion (the series is not convergent)
      sum = 1.0;
      term = 1.0;

      for (k=1;k<=20;k++) {
        term = term*k/x;
        sum += term;
      }
      return exp(x)/x * sum;
}
float feix(float x) {
      int maxit;
      float eps,euler,fpmin,fpmax;
      eps=6e-8;
      euler=.57721566;
      maxit=100;
      fpmin=1e-30;
      fpmax=1e30;
      int k;
      float sum,term;
      if (x == 0.0) return -fpmax;

      if (x < 0.0) return -fe1xb(-x);
      if (fabs(x) <= 40.) {
        // Power series around x=0

        sum = 1.0;
        term =1.0;
        k = 1;
        while ((fabs(term/sum) > eps)&&(k<=maxit)) {
          term = term*k*x/( (k+1.)*(k+1.));
          sum += term;
          k++;
        }
        return euler + log(x) + x*sum;
      }

      // Asymptotic expansion (the series is not convergent)
      sum = 1.0;
      term = 1.0;

      for (k=1;k<=20;k++) {
        term = term*k/x;
        sum += term;
      }
      return exp(x)/x * sum;
}


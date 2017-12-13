#include <stdlib.h>
#include <stdio.h>
#include <math.h>


extern double deix(double);

int main(void) {

	int i;
	double x;
	int ntot = 10000;
	double xmin = -50.;
	double xmax = 50.;
	double dx = (xmax-xmin)/(ntot-1);

	double *ans = (double *)malloc(sizeof(double)*ntot);

	for(i=0;i<ntot;i++) {
		x = xmin + i*dx;

		ans[i] = deix(x);
	}


	FILE *f;
	f = fopen("res.dat","w");
	fwrite(ans,ntot,sizeof(double),f);
	fclose(f);

	free(ans);
	return 1;
}


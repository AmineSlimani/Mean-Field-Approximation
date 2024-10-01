#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double J =1,T,m,prev_m,k = 1, epsilon = 1.e-12,beta,X,h,Cv;
int main() {
    FILE* fichier = fopen("champ.dat", "w");
    for (T = 0.00001; T <= 3.2; T += 0.01) {
        m = 3.0;
        do {
            prev_m = m;
            m = (2 * sinh(2 * J * m / (k * T)) + sinh(J * m / (k * T))) / 
                (cosh(2 * J * m / (k * T)) + cosh(J * m / (k * T)) + 0.5);
        } while (fabs(m - prev_m) / fabs(m) > epsilon );
        beta = 1/k*T;
        h = J*m ;
        
	X = (beta)*((4 * sinh(2 * J * m / (k * T)) + sinh(J * m / (k * T))) / 
                (cosh(2 * J * m / (k * T)) + cosh(J * m / (k * T)) + 0.5))-
                (beta*((2 * sinh(2 * J * m / (k * T)) + sinh(J * m / (k * T))) / 
                (cosh(2 * J * m / (k * T)) + cosh(J * m / (k * T)) + 0.5))*((2 * sinh(2 * J * m / (k * T))
                 + sinh(J * m / (k * T))) / (cosh(2 * J * m / (k * T)) + cosh(J * m / (k * T)) + 0.5))); 
      

	Cv = T*pow(beta, 2) * (
	    (4 * pow(J, 2) * pow(m, 2) * sinh(2 * J * m / (k * T)) + pow(J, 2) * pow(m, 2) * sinh(J * m / (k * T))) /
	    (cosh(2 * J * m / (k * T)) + cosh(J * m / (k * T)) + 0.5) -
	    pow((2 * J * m * sinh(2 * J * m / (k * T)) + J * m * sinh(J * m / (k * T))) /
	    (cosh(2 * J * m / (k * T)) + cosh(J * m / (k * T)) + 0.5), 2));
        printf("%.5f \t %.5f \t %.5f \t %.5f \t %.5f \n", T,m, X,Cv);
        fprintf(fichier, "%.5f \t %.5f \t %.5f\t %.5f \t %.5f  \n", T,m, X,Cv);
    }
    fclose(fichier);
    return 0;
}// By Amine Slimani




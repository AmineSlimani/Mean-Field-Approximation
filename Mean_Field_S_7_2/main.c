#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double J = 1., I, T, k = 1., Tpas = 0.01, m, eps = 1.e-12,m,prev_m,X,beta,Cv;

double f(double x, double z) {
    return (7 * sinh((7 / 2) * (J * x) / (k * z)) +
	 5 * sinh((5 / 2) * (J * x) / (k * z)) +
	 3 * sinh((3 / 2) * (J * x) / (k * z)) +
	 1 * sinh((1 / 2) * (J * x) / (k * z))
	) / (
	 2 * cosh((7 / 2) * (J * x) / (k * z)) +
	 2 * cosh((5 / 2) * (J * x) / (k * z)) +
	 2 * cosh((3 / 2) * (J * x) / (k * z)) +
	 2 * cosh((1 / 2) * (J * x) / (k * z))
	);
}


int main() {
    FILE *fichier;
    fichier = fopen("Champ_moy.dat", "w");
    m = 3.0/2.0;
    
    for (T = 0.00001; T <= 5.; T += 0.01) {
        m = 3.0;
        do {
            prev_m = m;
            m = f(m,T);
        } while (fabs(m - prev_m) / fabs(m) > eps );
        
        beta = 1.0/(k*T);

	X = (beta / 2.0) * (
		49 * sinh((7 / 2) * (J * m) / (k * T)) +
		25 * sinh((5 / 2) * (J * m) / (k * T)) +
		9 * sinh((3 / 2) * (J * m) / (k * T)) +
		1 * sinh((1 / 2) * (J * m) / (k * T))
	    ) / (
		2 * cosh((7 / 2) * (J * m) / (k * T)) +
		2 * cosh((5 / 2) * (J * m) / (k * T)) +
		2 * cosh((3 / 2) * (J * m) / (k * T)) +
		2 * cosh((1 / 2) * (J * m) / (k * T))
	    ) - beta * (
		7 * sinh((7 / 2) * (J * m) / (k * T)) +
		5 * sinh((5 / 2) * (J * m) / (k * T)) +
		3 * sinh((3 / 2) * (J * m) / (k * T)) +
		1 * sinh((1 / 2) * (J * m) / (k * T))
	    ) / (
		2 * cosh((7 / 2) * (J * m) / (k * T)) +
		2 * cosh((5 / 2) * (J * m) / (k * T)) +
		2 * cosh((3 / 2) * (J * m) / (k * T)) +
		2 * cosh((1 / 2) * (J * m) / (k * T))
	    ) * (
		7 * sinh((7 / 2) * (J * m) / (k * T)) +
		5 * sinh((5 / 2) * (J * m) / (k * T)) +
		3 * sinh((3 / 2) * (J * m) / (k * T)) +
		1 * sinh((1 / 2) * (J * m) / (k * T))
	    ) / (
		2 * cosh((7 / 2) * (J * m) / (k * T)) +
		2 * cosh((5 / 2) * (J * m) / (k * T)) +
		2 * cosh((3 / 2) * (J * m) / (k * T)) +
		2 * cosh((1 / 2) * (J * m) / (k * T))
	    );
        
       Cv = (beta*beta / 2.0) * (
		49* (J * m) *(J * m) * sinh((7 / 2) * (J * m) / (k * T)) +
		25 * (J * m)* (J * m)* sinh((5 / 2) * (J * m) / (k * T)) +
		9 * (J * m)* (J * m)* sinh((3 / 2) * (J * m) / (k * T)) +
		1 * (J * m)* sinh((1 / 2) * (J * m) / (k * T))
	    ) / (
		2 * cosh((7 / 2) * (J * m) / (k * T)) +
		2 * cosh((5 / 2) * (J * m) / (k * T)) +
		2 * cosh((3 / 2) * (J * m) / (k * T)) +
		2 * cosh((1 / 2) * (J * m) / (k * T))
	    ) - beta*beta * (
		7 * (J * m)* sinh((7 / 2) * (J * m) / (k * T)) +
		5* (J * m) * sinh((5 / 2) * (J * m) / (k * T)) +
		3 * (J * m)* sinh((3 / 2) * (J * m) / (k * T)) +
		1 * (J * m)* sinh((1 / 2) * (J * m) / (k * T))
	    ) / (
		2 * cosh((7 / 2) * (J * m) / (k * T)) +
		2 * cosh((5 / 2) * (J * m) / (k * T)) +
		2 * cosh((3 / 2) * (J * m) / (k * T)) +
		2 * cosh((1 / 2) * (J * m) / (k * T))
	    ) * (
		7 * (J * m)* sinh((7 / 2) * (J * m) / (k * T)) +
		5 * (J * m)* sinh((5 / 2) * (J * m) / (k * T)) +
		3 * (J * m)* sinh((3 / 2) * (J * m) / (k * T)) +
		1 * (J * m)* sinh((1 / 2) * (J * m) / (k * T))
	    ) / (
		2 * cosh((7 / 2) * (J * m) / (k * T)) +
		2 * cosh((5 / 2) * (J * m) / (k * T)) +
		2 * cosh((3 / 2) * (J * m) / (k * T)) +
		2 * cosh((1 / 2) * (J * m) / (k * T))
	    );
                    
        
        printf("%.2lf \t %.2lf\t %.2lf \t %.2lf \n", T, m,X,Cv);
        fprintf(fichier, "%.2lf \t %.2lf\t %.2lf \t  %.2lf\n", T, m,X,Cv);
    }
    fclose(fichier);
    return 0;
}

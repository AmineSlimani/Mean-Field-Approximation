#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define KB 1.0
#define J 1.0
#define N ( * 1 * 1)
#define Ms 0.4256
int main() {
    FILE* fichier = fopen("Flibre8.dat", "w");
    double M[] = {
        2.00000, 2.00000, 2.00000, 1.99995, 1.99872, 1.99310,
        1.98059, 1.96038, 1.93248, 1.89706, 1.85411,
        1.80337, 1.74424, 1.67581, 1.59676, 1.50523,
        1.39857, 1.27272, 1.12100, 0.93054, 0.66869,
        0.00000,-0.66869, -0.93054, -1.12100, -1.27272, -1.39857,
    -1.50523, -1.59676, -1.67581, -1.74424, -1.80337,
    -1.85411, -1.89706, -1.93248, -1.96038, -1.98059,
    -1.99310, -1.99872, -1.99995, -2.00000, -2.00000, -2.00000}; 

    double T, F,S;
    int i = 0;

    for (T = 0.00001; T <= 4.3; T += 0.1) {
        double m = M[i];
        F = KB * T*N * log(2*cosh(2 * J * m / (KB * T)) +2* cosh(J * m / (KB * T)) + 1);


	printf("%.5f \t %.5f \t %.5f  \n", T, m, F);
	fprintf(fichier, "%.5f \t %.5f \t %.5f \n", T, m, F);

        i++;
    }

    fclose(fichier);
    return 0;
}// Par Amine Slimani




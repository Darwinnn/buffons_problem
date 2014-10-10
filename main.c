#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define PI 3.1415926535
#define RAD(x) (x * PI/180.0)

main() {

    double x; /* the center of needle to the closest line */
    double y; /* l/2*sin(DEG) */
    double deg; /* Angle degree of a needle */
    double P; /* Probabillity */
    double a_pi; /* Calculated Pi */
    int events = 0; 
    double l = .8; /* Lenghts of a needle */
    int t_len = 2; /* Lenghts between lines */
    int attempts = 500000000; 

    int i;
    srand((unsigned)time(NULL));

    for(i=0; i<=attempts; i++) {
        x = (double)rand()/((double)RAND_MAX * (double)t_len); 
        deg = RAD(rand() % 360);

        if(x <= ((l/2.0)*(sin(deg)))) {
            //printf("Positive: %d\t P=%f\t x=%f\t deg=%f\n", i, (double)events/(double)i, x, deg);
            events++;
        }
    }
        P = (double)events/(double)attempts;
        printf("There have been %d positive trials out of %d attempts\n", events, attempts);
        printf("Input parameters: t = %d; l = %f; P = %f;\n", t_len, l, P);
        a_pi = (2*l)/(t_len*P);
        printf("Calculated Pi = %.10f\n", a_pi);

        return 0;

}


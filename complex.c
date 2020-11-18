#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"

struct cplx {
    double reel;
    double imaginaire;
};

int main(){
    struct cplx complex1 = make_cplx(94, 44);
    struct cplx complex2 = make_cplx(23, -34);
    descript(mulCplx(&complex1, &complex2));
    return 0;
}

struct cplx make_cplx(double reel, double imaginaire){
    struct cplx result;
    result.imaginaire = imaginaire;
    result.reel = reel;
    return result;
}
struct cplx make_cplx2(double rho, double theta){
    struct cplx complex;
    complex.reel = rho*cos(theta);
    complex.imaginaire = rho*sin(theta);
    return complex;
}

double moduleCplx(struct cplx *complex){
    double result = sqrt((pow(complex->reel, 2) + pow(complex->imaginaire, 2)));
    return result;
}
double argumentCplx(struct cplx *complex){
    double result;
    result = atan(complex->imaginaire / complex->reel);
    return result;
}
struct cplx conjugue(struct cplx *complex){
    struct cplx ncomp;
    ncomp.reel = complex->reel;
    ncomp.imaginaire = -complex->imaginaire;
    return ncomp;
}
struct cplx divCplx(struct cplx *complex1, struct cplx *complex2){
    struct cplx new, cjg1, n1, n2;
    cjg1 = conjugue(complex2);
    n1 = mulCplx(complex1, &cjg1);
    n2 = mulCplx(complex2, &cjg1);
    new.reel = n1.reel / n2.reel;
    new.imaginaire = n1.imaginaire / n2.reel;
    return new;
}
struct cplx mulCplx(struct cplx *complex1, struct cplx *complex2){
    struct cplx new;
    new.reel = -complex1->imaginaire * complex2->imaginaire + complex1->reel * complex2->reel;
    new.imaginaire = complex1->imaginaire * complex2->reel + complex1->reel * complex2->imaginaire;
    return new;
}
struct cplx addCplx(struct cplx *complex1, struct cplx *complex2){
    struct cplx new;
    new.reel = complex1->reel + complex2->reel;
    new.imaginaire = complex1->imaginaire + complex2->imaginaire;
    return new;
}
struct cplx subCplx(struct cplx *complex1, struct cplx *complex2){
    struct cplx new;
    new.reel = complex1->reel - complex2->reel;
    new.imaginaire = complex1->imaginaire - complex2->imaginaire;
    return new;
}
void print_cplx(struct cplx complex){
    char sign = '+';
    double affI = complex.imaginaire;
    if(complex.imaginaire < 0) {
        sign = '-';
        affI = affI-(affI*2);
    }
    printf("%f %c i%f\n", complex.reel, sign, affI);
}
void describe(struct cplx complex){
    printf("\nComplexe : ");
    print_cplx(complex);
    printf("\nModule (rho) --> %f\nArgument (Theta) --> %f\n\n", moduleCplx(&complex), argumentCplx(&complex));
    printf("Conjugué --> ");
    print_cplx(conjugue(&complex));
    printf("\n");
}
struct cplx;
void print_cplx(struct cplx complex);
struct cplx make_cplx(double reel, double imaginaire);
struct cplx make_cplx2(double rho, double theta);
struct cplx addCplx(struct cplx *complex1, struct cplx *complex2);
struct cplx subCplx(struct cplx *complex1, struct cplx *complex2);
struct cplx mulCplx(struct cplx *complex1, struct cplx *complex2);
struct cplx divCplx(struct cplx *complex1, struct cplx *complex2);
struct cplx conjugue(struct cplx *complex);
double moduleCplx(struct cplx *complex);
double argumentCplx(struct cplx *complex);
void describe(struct cplx complex);
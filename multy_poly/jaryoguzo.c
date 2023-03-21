#include<stdio.h>
#define MAX_DEGREE 101
typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

polynomial poly_multy(polynomial A, polynomial B)
{
	polynomial C;
	int i, j;
	for (i = 0; i <= A.degree + B.degree; i++)
		C.coef[i] = 0;
	C.degree = A.degree + B.degree;
	for (i = 0; i <= A.degree; i++) {
		for (j = 0; j <= B.degree; j++)
			C.coef[i + j] += A.coef[i] * B.coef[j];
	}
	return C;
}
void print_poly(polynomial p) {
	for (int i = p.degree; i > 0; i--)
		printf("%.1fx^%d +", p.coef[p.degree - i], i);
	printf("%.1lf\n", p.coef[p.degree]);
}
void result(polynomial result1, polynomial result2, polynomial result3) {
	print_poly(result1);
	print_poly(result2);
	printf("--------------------------------------------------------------------------------------\n");
	print_poly(result3);
}
int main(void)
{
	polynomial a = { 3,{4,3,2,1} };
	polynomial b = { 2,{3,2,8} };
	polynomial c;
	polynomial d = { 6,{7,0,0,5,9,0,1} };
	polynomial e = { 3,{5,2,1,10} };
	polynomial f;

	c = poly_multy(a, b);
	f = poly_multy(d, e);

	result(a, b, c);
	printf("\n");
	result(d, e, f);

	return 0;
}
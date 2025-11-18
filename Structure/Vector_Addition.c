#include <stdio.h>
#include <math.h>

struct vector{
    int i;
    int j;
};
    
void sumVector(struct vector v1, struct vector v2);
void magVector(struct vector v);

    
int main() {

    
    struct vector v1;
    printf("Enter 1st vector (i,j): ");
    scanf("%d %d", &v1.i, &v1.j);
    
    struct vector v2;
    printf("Enter 2nd vector in (i,j): ");
    scanf("%d %d", &v2.i, &v2.j);
    
    printf("Vector 1: %di + %dj \nVector 2: %di + %dj \n\n", v1.i, v1.j, v2.i, v2.j);
    sumVector(v1,v2);
    magVector(v1);
    return 0;
}

void sumVector(struct vector v1, struct vector v2){
    struct vector sum = {v1.i + v2.i, v1.j + v2.j};
    printf("%di + %dj + %di + %dj = %di + %dj", v1.i, v1.j, v2.i, v2.j, sum.i, sum.j);
}

void magVector(struct vector v){
    float magnitude = sqrt(v.i * 1.0 * v.i + v.j * v.j);
    printf("\n\nMagnitude of vector %di + %dj = %.2f", v.i, v.j, magnitude);
}

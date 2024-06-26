#include <stdio.h>
struct poly {
    int coef, expo;
};

int getPolynomial(struct poly polynomial[]) {
    
    int coef, i=0, n;
    
    printf("Enter highest power : ");
    scanf("%d", &n);
    
    while(n >= 0) {
        printf("Enter coefficient of %d : ", n);
        scanf("%d", &coef);
        if(coef != 0) {
            polynomial[i].expo = n;
            polynomial[i].coef = coef;
            i++;
        }
        
        n--;
    }
    return i;
}

void showPolynomial(struct poly polynomial[], int size) {
    int i;
    for(i=0; i<size; i++){
        if(!polynomial[i].expo) {
            printf("%d ", polynomial[i].coef);
            continue;
        }
        printf("%dx^%d ", polynomial[i].coef, polynomial[i].expo);
        if(i==size-1)
         continue;
        printf(" + ");
    }
}
int addPolynomial(struct poly polynomial1[], int size1, struct poly polynomial2[], int size2, struct poly res[]) {
    
    int i,j,k;
    for(i =0,j=0,k=0; j<size1 && k<size2; i++ ) {
        
        if(polynomial1[j].expo == polynomial2[k].expo) {
            res[i].coef = polynomial1[j].coef + polynomial2[k].coef;
            res[i].expo = polynomial1[j].expo;
            j++;k++;
        }
        else if(polynomial1[j].expo > polynomial2[k].expo) {
            res[i].expo = polynomial1[j].expo;
            res[i].coef = polynomial1[j].coef;
            j++;
        }
        else {
            res[i].expo = polynomial2[k].expo;
            res[i].coef = polynomial2[k].coef;
            k++;
        }
    }
    if(j==size1) {
        while(k<size2) {
            res[i].expo = polynomial2[k].expo;
            res[i].coef = polynomial2[k].coef;
            k++;
            i++;
        }
    }
    if(k==size2) {
        while(j<size1) {
            res[i].expo = polynomial1[j].expo;
            res[i].coef = polynomial1[j].coef;
            j++;i++;
        }
    }
    
    return i;
}
int main()
{
    struct poly poly1[10], poly2[10], res[20];
    int s1, s2, sres;
    
    printf("Enter polynomial 1 : \n");
    s1 = getPolynomial(poly1);
    
    printf("Enter polynomial 2 : \n");
    s2 = getPolynomial(poly2);

    showPolynomial(poly1, s1);
    printf("\n");
    showPolynomial(poly2, s2);
    
    sres = addPolynomial(poly1, s1, poly2, s2, res);
    
    printf("\n\n");
    showPolynomial(res, sres);
    
    return 0;
}

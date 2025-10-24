#include <stdio.h>
#include <math.h>

void print_menu();
void add();
void subtract();
void multiply();
void divide();
void modulus();
void power();

int main(){
    int choice;
    while(1){
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 0){
            break;
        }
        
        else if (choice > 6 || choice < 0){
            continue;
        }
        
        switch(choice){
            case 1:{
                add();
                break;
            }
            case 2:{
                subtract();
                break;
            }
            case 3:{
                multiply();
                break;
            }
            case 4:{
                divide();
                break;
            }
            case 5:{
                modulus();
                break;
            }
            case 6:{
                power();
                break;
            }
        }
    }
    
    return 0;
}

void print_menu(){
    printf("\n\n\033[1;36m------------------------------------------------------------\033[0m\n");
    printf("\033[1;35mWelcome to Calculator!\033[0m\n");
    printf("Select your desired option from menu: \n");
    printf("\n0 -> Exit");
    printf("\n1 -> Addition");
    printf("\n2 -> Substraction");
    printf("\n3 -> Multiplication");
    printf("\n4 -> Division");
    printf("\n5 -> Modulus");
    printf("\n6 -> Power\n\n");
}

void add(){
    float a, b;
    printf("\nEnter 1st number: ");
    scanf("%f", &a);
    printf("Enter 2nd number: ");
    scanf("%f", &b);
    printf("%f + %f = %f", a, b, a+b);
}

void subtract(){
    float a, b;
    printf("\nEnter 1st number: ");
    scanf("%f", &a);
    printf("Enter 2nd number: ");
    scanf("%f", &b);
    printf("%f - %f = %f", a, b, a-b);
}

void multiply(){
    float a, b;
    printf("\nEnter 1st number: ");
    scanf("%f", &a);
    printf("Enter 2nd number: ");
    scanf("%f", &b);
    printf("%f X %f = %f", a, b, a*b);
}

void divide(){
    float a, b;
    printf("\nEnter 1st number: ");
    scanf("%f", &a);
    printf("Enter 2nd number: ");
    scanf("%f", &b);
    if(b==0){
        printf("\033[1;31mValues entered by you are incorrect as per rules of division!\033[0m");
    }
    
    else{
        printf("%f ÷ %f = %f", a, b, a / b);
    }
}

void modulus(){
    int a, b;
    printf("\nEnter 1st number: ");
    scanf("%d", &a);
    printf("Enter 2nd number: ");
    scanf("%d", &b);
    if(b==0){
        printf("\033[1;31mValues entered by you are incorrect as per rules of modulus!\033[0m");
    }
    
    else{
        printf("%d %% %d = %d", a, b, a % b);
    }
}

void power(){
    float a, b;
    printf("\nEnter 1st number: ");
    scanf("%f", &a);
    printf("Enter 2nd number: ");
    scanf("%f", &b);
    printf("%f ^ %f = %f", a, b, pow(a,b));
}
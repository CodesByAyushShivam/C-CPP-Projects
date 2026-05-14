#include <stdio.h>
#include <time.h>

void printList();
float price(int, float);
float calGst(float, int);
int gstrate();

struct item {
    float price;
    char name[20];
    int id;
    float quant;
    int gstRate;
    float gstAmount;
};


int main(){
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printList();
    struct item list[n];
    struct item *ptr;
    ptr = list;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the id of the item %d: ", i+1);
        scanf("%d", &list[i].id);
        printf("Enter the quantity item %d: ", i+1);
        scanf("%f", &list[i].quant);
        list[i].price = price(list[i].id, list[i].quant);
        list[i].gstRate = gstrate();
        list[i].gstAmount = calGst(list[i].price, list[i].gstRate);
    }
    
    FILE *file;
    file = fopen("reciept_history.txt", "a");
    fprintf(file, "\n\n\n%c Reciept Generated at: %ld", '#', time(NULL));
    fclose(file);
    
    return 0;
}

void printList(){
    printf("\n\nProduct and ID: \n\n");
    printf("1. Curd\t\t Price: 70\n");
    printf("2. Pea\t\t Price: 50\n");
    printf("3. Paneer\t Price: 350\n");
    printf("4. IceCream\t Price: 50\n");
    printf("5. Milk\t\t Price: 58\n");
    printf("6. MilkPowder\t Price: 35\n");
    printf("7. Egg\t\t Price: 82\n");
}

float price(int id, float quant){
    switch(id){
        case 1:{
            return quant*70;
            break;
        }
        case 2:{
            return quant*50;
            break;
        }
        case 3:{
            return quant*350;
            break;
        }
        case 4:{
            return quant*50;
            break;
        }
        case 5:{
            return quant*58;
            break;
        }
        case 6:{
            return quant*35;
            break;
        }
        case 7:{
            return quant*82;
            break;
        }
        default:{
            return 0;
            break;
        }
    }
}

float calGst(float price, int rate){
    return (price * rate) / 100 ;
}

int gstrate() {
    int n;
    printf("Choose GST rate for this product. Enter the serial number against the required GST to get it as input: \n 1. 5%c \n 2. 12%c \n 3. 18%c \n 4. 28%c \n 5. 40%c \n Any other value will result in inclusion of 0%c GST on the final bill !! \n Input:", '%', '%', '%', '%', '%', '%');
    scanf("%d", &n);
    switch (n)
    {
    case 1:
    {
        printf("5%c applied on your product \n", '%');
        return 5;
    }

    case 2:
    {
        printf("12%c applied on your product \n", '%');
        return 12;
    }

    case 3:
    {
        printf("18%c applied on your product \n", '%');
        return 18;
    }

    case 4:
    {
        printf("28%c applied on your product \n", '%');
        return 28;
    }

    case 5:
    {
        printf("40%c applied on your product \n", '%');
        return 40;
        break;
    }

    default:
    {
        printf("No applied on your product \n");
        return 0;
    }
    }
}

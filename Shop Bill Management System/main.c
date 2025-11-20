#include <stdio.h>

void printList();
int price(int, float);

struct item
{
    int price;
    char name[20];
    int id;
    float quant;
    int gst;
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
    }
    
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

int price(int id, float quant){
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
    }
}

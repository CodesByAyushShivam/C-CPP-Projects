#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

void printList();
float price(int, float);
float calGst(float, int);
int gstrate(int);
char *getNamebyId(int);
float getPricebyId(int);

struct item
{
    float unitPrice;
    float price;
    char name[20];
    int id;
    float quant;
    int gstRate;
    float gstAmount;
};

char *generateReceipt(struct item[], int);

int main()
{
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printList();
    struct item list[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the id of the item %d: ", i + 1);
        scanf("%d", &list[i].id);
        if (list[i].id < 1 || list[i].id > 7)
        {
            printf("Invalid ID! Try again.\n");
            i--;
            continue;
        }
        strcpy(list[i].name, getNamebyId(list[i].id));
        list[i].unitPrice = getPricebyId(list[i].id);
        printf("Enter the quantity item %d: ", i + 1);
        scanf("%f", &list[i].quant);
        list[i].price = price(list[i].id, list[i].quant);
        list[i].gstRate = gstrate(list[i].id);
        list[i].gstAmount = calGst(list[i].price, list[i].gstRate);
    }

    char *receipt = generateReceipt(list, n);

    if (receipt == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    printf("%s", receipt);

    FILE *file;
    file = fopen("receipt_history.txt", "a");
    if (file == NULL)
    {
        printf("Error opening file");
        return 1;
    }
    time_t now;
    struct tm *ist;
    char buffer[100];

    now = time(NULL);
    ist = localtime(&now);

    strftime(buffer, sizeof(buffer), "%d-%m-%Y %I:%M:%S %p", ist);
    fprintf(file, "\n\n\n%s", receipt);
    fclose(file);

    return 0;
}

void printList()
{
    printf("\n\nProduct and ID: \n\n");
    printf("1. %s\t\t Price: %.2f\n", getNamebyId(1), getPricebyId(1));
    printf("2. %s\t\t Price: %.2f\n", getNamebyId(2), getPricebyId(2));
    printf("3. %s\t Price: %.2f\n", getNamebyId(3), getPricebyId(3));
    printf("4. %s\t Price: %.2f\n", getNamebyId(4), getPricebyId(4));
    printf("5. %s\t\t Price: %.2f\n", getNamebyId(5), getPricebyId(5));
    printf("6. %s\t Price: %.2f\n", getNamebyId(6), getPricebyId(6));
    printf("7. %s\t\t Price: %.2f\n", getNamebyId(7), getPricebyId(7));
}

float price(int id, float quant)
{
    switch (id)
    {
    case 1:
    {
        return quant * getPricebyId(1);
    }
    case 2:
    {
        return quant * getPricebyId(2);
    }
    case 3:
    {
        return quant * getPricebyId(3);
    }
    case 4:
    {
        return quant * getPricebyId(4);
    }
    case 5:
    {
        return quant * getPricebyId(5);
    }
    case 6:
    {
        return quant * getPricebyId(6);
    }
    case 7:
    {
        return quant * getPricebyId(7);
    }
    default:
    {
        return 0.00;
    }
    }
}

float calGst(float price, int rate)
{
    return (price * rate) / 100;
}

int gstrate(int id)
{
    if (id == 3 || id == 6)
    {
        printf("5%c GST applied on your product \n", '%');
        return 5;
    }

    else if (id == 4)
    {
        printf("18%c GST applied on your product \n", '%');
        return 18;
    }

    else
    {
        printf("0%c GST applied on your product \n", '%');
        return 0;
    }
}

char *getNamebyId(int id)
{
    switch (id)
    {
    case 1:
    {
        return "Curd";
    }
    case 2:
    {
        return "Pea";
    }
    case 3:
    {
        return "Paneer";
    }
    case 4:
    {
        return "IceCream";
    }
    case 5:
    {
        return "Milk";
    }
    case 6:
    {
        return "MilkPowder";
    }
    case 7:
    {
        return "Egg";
    }
    default:
    {
        return "NULL";
    }
    }
}

float getPricebyId(int id)
{
    switch (id)
    {
    case 1:
    {
        return 70.00;
    }
    case 2:
    {
        return 50.00;
    }
    case 3:
    {
        return 350.00;
    }
    case 4:
    {
        return 50.00;
    }
    case 5:
    {
        return 58.00;
    }
    case 6:
    {
        return 35.00;
    }
    case 7:
    {
        return 82.00;
    }
    default:
    {
        return 0.00;
    }
    }
}


//AI Generated Reciept generation logic based on passed arguments and available data in struct item list[]
char *generateReceipt(struct item list[], int n)
{

    char *receipt = (char *)malloc(5000 * sizeof(char));

    if (receipt == NULL)
    {
        return NULL;
    }

    float subtotal = 0.00;
    float totalGst = 0.00;
    float grandTotal = 0.00;

    time_t now;
    struct tm *ist;
    char buffer[100];

    now = time(NULL);
    ist = localtime(&now);

    strftime(buffer, sizeof(buffer), "%d-%m-%Y %I:%M:%S %p", ist);

    int len = 0;

    len += sprintf(receipt + len,
                   "========================================\n");

    len += sprintf(receipt + len,
                   "            GROCERY RECEIPT\n");

    len += sprintf(receipt + len,
                   "========================================\n\n");

    len += sprintf(receipt + len,
                   "Generated at: %s\n\n", buffer);

    len += sprintf(receipt + len,
                   "-------------------------------------------------------------\n");

    len += sprintf(receipt + len,
                   "%-15s %-8s %-10s %-10s %-10s\n",
                   "Item", "Qty", "Price", "GST", "Total");

    len += sprintf(receipt + len,
                   "-------------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {

        float finalPrice =
            list[i].price + list[i].gstAmount;

        subtotal += list[i].price;
        totalGst += list[i].gstAmount;

        len += sprintf(receipt + len,
                       "%-15s %-8.2f %-10.2f %-10.2f %-10.2f\n",

                       list[i].name,
                       list[i].quant,
                       list[i].price,
                       list[i].gstAmount,
                       finalPrice);
    }

    grandTotal = subtotal + totalGst;

    len += sprintf(receipt + len,
                   "-------------------------------------------------------------\n");

    len += sprintf(receipt + len,
                   "Subtotal: %.2f\n", subtotal);

    len += sprintf(receipt + len,
                   "Total GST: %.2f\n", totalGst);

    len += sprintf(receipt + len,
                   "Grand Total: %.2f\n", grandTotal);

    len += sprintf(receipt + len,
                   "\n========================================\n");

    len += sprintf(receipt + len,
                   "         THANK YOU VISIT AGAIN\n");

    len += sprintf(receipt + len,
                   "========================================\n");

    return receipt;
}

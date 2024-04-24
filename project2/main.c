#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct 
{
    char *name;
    float price;
    int quantity;
} Item;

void add_item(Item **bill, int *numItems, int *capacity) 
{
    if (*numItems >= *capacity) 
    {
        *capacity *= 2;
        *bill = realloc(*bill, *capacity * sizeof(Item));
    }

    (*bill)[*numItems].name = malloc(MAX_NAME_LENGTH * sizeof(char));

    printf("Enter item name: ");
    scanf("%s", (*bill)[*numItems].name);
    printf("Enter item price: ");
    scanf("%f", &(*bill)[*numItems].price);
    printf("Enter quantity: ");
    scanf("%d", &(*bill)[*numItems].quantity);
    printf("Item added to bill.\n");
    (*numItems)++;
}

float calculate_total(Item *bill, int numItems) 
{
    float total = 0;
    for (int i = 0; i < numItems; i++) 
    {
        total += bill[i].price * bill[i].quantity;
    }
    return total;
}

void generate_receipt(Item *bill, int numItems, char *customerName, char *customerAddress, float discount) 
{
    float total_cost = calculate_total(bill, numItems);
    float discount_amount = total_cost * (discount / 100.0);
    float discounted_total = total_cost - discount_amount;

    printf("********** Grocery Bill **********\n");
    printf("Customer Name: %s\n", customerName);
    printf("Customer Address: %s\n", customerAddress);
    printf("----------------------------------\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s: $%.2f x %d = $%.2f\n", bill[i].name, bill[i].price, bill[i].quantity, bill[i].price * bill[i].quantity);
    }
    printf("----------------------------------\n");
    printf("Total: $%.2f\n", total_cost);
    printf("Discount: %.2f%%\n", discount);
    printf("Discounted Amount: $%.2f\n", discount_amount);
    printf("Discounted Total: $%.2f\n\n", discounted_total);
}

int main() 
{
    int capacity = 5;
    int numItems = 0;
    Item *bill = malloc(capacity * sizeof(Item));
    char customerName[MAX_NAME_LENGTH];
    char customerAddress[MAX_NAME_LENGTH];
    float discount;

    printf("Enter customer name: ");
    scanf("%s", customerName);
    printf("Enter customer address: ");
    scanf("%s", customerAddress);
    printf("Enter discount percentage: ");
    scanf("%f", &discount);

    int choice;
    do 
    {
        printf("1. Add Item\n");
        printf("2. Generate Receipt\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                add_item(&bill, &numItems, &capacity);
                break;
            case 2:
                generate_receipt(bill, numItems, customerName, customerAddress, discount);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    for (int i = 0; i < numItems; i++) 
    {
        free(bill[i].name);
    }
    free(bill);

    return 0;
}

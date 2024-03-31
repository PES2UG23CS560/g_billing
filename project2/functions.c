#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// Function to add an item to the bill
void add_item(char ***names, float *prices, int *quantities, int *numItems, int *capacity) {
    if (*numItems >= *capacity) {
        // Increase capacity using realloc
        *capacity *= 2;
        *names = realloc(*names, *capacity * sizeof(char*));
        prices = realloc(prices, *capacity * sizeof(float));
        quantities = realloc(quantities, *capacity * sizeof(int));
    }

    // Allocate memory for the new name
    (*names)[*numItems] = malloc(MAX_NAME_LENGTH * sizeof(char));

    printf("Enter item name: ");
    scanf("%s", (*names)[*numItems]);
    printf("Enter item price: ");
    scanf("%f", &prices[*numItems]);
    printf("Enter quantity: ");
    scanf("%d", &quantities[*numItems]);
    printf("Item added to bill.\n");
    (*numItems)++;
}

// Function to calculate the total cost of the bill
float calculate_total(float *prices, int *quantities, int numItems) {
    float total = 0;
    for (int i = 0; i < numItems; i++) {
        total += prices[i] * quantities[i];
    }
    return total;
}

// Function to generate the bill
void generate_receipt(char **names, float *prices, int *quantities, int numItems, char *customerName, char *customerAddress, float discount) {
    float total_cost = calculate_total(prices, quantities, numItems);
    float discount_amount = total_cost * (discount / 100.0);
    float discounted_total = total_cost - discount_amount;

    printf("********** Grocery Bill **********\n");
    printf("Customer Name: %s\n", customerName);
    printf("Customer Address: %s\n", customerAddress);
    printf("----------------------------------\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s: $%.2f x %d = $%.2f\n", names[i], prices[i], quantities[i], prices[i] * quantities[i]);
    }
    printf("----------------------------------\n");
    printf("Total: $%.2f\n", total_cost);
    printf("Discount: %.2f%%\n", discount);
    printf("Discounted Amount: $%.2f\n", discount_amount);
    printf("Discounted Total: $%.2f\n", discounted_total);
    printf("\n");
}

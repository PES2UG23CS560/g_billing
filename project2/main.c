#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include string.h for strcspn function
#include "functions.h"

int main() {
    char **names = malloc(INITIAL_CAPACITY * sizeof(char*));
    float *prices = malloc(INITIAL_CAPACITY * sizeof(float));
    int *quantities = malloc(INITIAL_CAPACITY * sizeof(int));
    int numItems = 0;
    int capacity = INITIAL_CAPACITY;
    int choice;
    float discount;

    // Getting customer details
    char customerName[MAX_NAME_LENGTH];
    char customerAddress[MAX_ADDRESS_LENGTH];

    printf("Enter customer name: ");
    scanf("%s", customerName);

    printf("Enter customer address: ");
    getchar(); // Clear the newline character from the buffer
    fgets(customerAddress, MAX_ADDRESS_LENGTH, stdin);
    customerAddress[strcspn(customerAddress, "\n")] = '\0'; // Remove trailing newline

    printf("Enter discount percentage: ");
    scanf("%f", &discount);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add item\n");
        printf("2. Generate bill\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(&names, prices, quantities, &numItems, &capacity);
                break;
            case 2:
                generate_receipt(names, prices, quantities, numItems, customerName, customerAddress, discount);
                break;
            case 3:
                printf("Thank you for shopping with us!\n");

                // Free memory for each name
                for (int i = 0; i < numItems; i++) {
                    free(names[i]);
                }

                // Free memory for the names array
                free(names);

                free(prices);
                free(quantities);
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

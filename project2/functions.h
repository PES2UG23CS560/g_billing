#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define INITIAL_CAPACITY 10
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

void add_item(char ***names, float *prices, int *quantities, int *numItems, int *capacity);
float calculate_total(float *prices, int *quantities, int numItems);
void generate_receipt(char **names, float *prices, int *quantities, int numItems, char *customerName, char *customerAddress, float discount);

#endif /* FUNCTIONS_H */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
constexpr size_t ITEM_DESCRIPTION_SIZE = 20;

constexpr char INVENTORY_OLD_TEXT[] = "inventory-old.txt",
               INVENTORY_OLD[] = "inventory-old.bin",
               INVENTORY_NEW[] = "inventory-new.bin",
               ORDERS_TEXT[] = "orders.txt", ORDERS[] = "orders.bin";

typedef unsigned short index_t;
constexpr index_t NONE = USHRT_MAX; // Sentinel
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winitializer-overrides"
const index_t id_to_index[] = {
    [0 ... 301] = NONE, [102] = 0, [104] = 1, [301] = 2};
#pragma clang diagnostic pop
// Maps inventory item id to its inventory index.

typedef struct {
  int id;
  char description[ITEM_DESCRIPTION_SIZE];
  int quantity;
} Item;
// A record in the inventory

typedef struct {
  int id;
  int quantity;
} Order;

Item item;
Order order;
// To be used in all functions as a temporary variable.

// Gracefully exit the program if there is a problem during `fopen`.
FILE *fopen_or_die(const char *filename, const char *mode) {
  FILE *fp = fopen(filename, mode);
  if (!fp) {
    perror(filename);
    exit(EXIT_FAILURE);
  }
  return fp;
}

void inventory_text_to_binary(const char *filename_text,
                              const char *filename_binary) {
  // YOUR CODE HERE
}

void orders_text_to_binary(const char *filename_text,
                           const char *filename_binary) {
  // YOUR CODE HERE
}

void inventory_copy(const char *filename_source,
                    const char *filename_destination) {
  // YOUR CODE HERE
}

// Updates a single item's quantity in the inventory according to the order
bool inventory_update_item_quantity(FILE *fp, Order order) {
  // YOUR CODE HERE
}

// Reads orders one by one and updates the inventory using
// `inventory_update_item_quantity()`.
void orders_process(FILE *fp_orders, FILE *fp_inventory) {
  // YOUR CODE HERE
}

int main() {
  inventory_text_to_binary(INVENTORY_OLD_TEXT, INVENTORY_OLD);
  orders_text_to_binary(ORDERS_TEXT, ORDERS);
  inventory_copy(INVENTORY_OLD, INVENTORY_NEW);

  FILE *fp_inventory = fopen_or_die(INVENTORY_NEW, "r+b"),
       *fp_orders = fopen_or_die(ORDERS, "rb");

  orders_process(fp_orders, fp_inventory);

  fclose(fp_inventory);
  fclose(fp_orders);
}

#include <stdio.h>

#define MAX_PARTITIONS 10

int partitions[MAX_PARTITIONS]; // array to hold partition sizes
int num_partitions = 0; // number of partitions

int allocate_memory(int size) {
  int i;
  for (i = 0; i < num_partitions; i++) {
    if (partitions[i] >= size) { // if partition is big enough
      partitions[i] -= size; // reduce partition size
      return i; // return partition index
    }
  }
  return -1; // no partition available
}

void deallocate_memory(int index, int size) {
  partitions[index] += size; // increase partition size
}

int main() {
  int choice, size, index;
  while (1) {
    printf("\n1. Add partition\n2. Allocate memory\n3. Deallocate memory\n4. Display partitions\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        if (num_partitions < MAX_PARTITIONS) {
          printf("Enter partition size: ");
          scanf("%d", &partitions[num_partitions]);
          num_partitions++;
          printf("Partition added.\n");
        } else {
          printf("Maximum number of partitions reached.\n");
        }
        break;
      case 2:
        printf("Enter memory size: ");
        scanf("%d", &size);
        index = allocate_memory(size);
        if (index == -1) {
          printf("Memory allocation failed.\n");
        } else {
          printf("Memory allocated from partition %d.\n", index);
        }
        break;
      case 3:
        printf("Enter partition index and memory size to deallocate: ");
        scanf("%d %d", &index, &size);
        deallocate_memory(index, size);
        printf("Memory deallocated from partition %d.\n", index);
        break;
      case 4:
        printf("Partitions:\n");
        for (int i = 0; i < num_partitions; i++) {
          printf("%d: %d\n", i, partitions[i]);
        }
        break;
      case 5:
        return 0;
      default:
        printf("Invalid choice.\n");
    }
  }
}

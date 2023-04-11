#include <stdio.h>

#define MAX_PARTITIONS 10

int partitions[MAX_PARTITIONS];
int num_partitions = 0;

int allocate_memory(int size) {
    int best_index = -1;
    int best_fit = 99999999;

    for (int i = 0; i < num_partitions; i++) {
        if (partitions[i] >= size && partitions[i] < best_fit) {
            best_fit = partitions[i];
            best_index = i;
        }
    }

    if (best_index == -1) {
        return -1; // Allocation failed
    }

    partitions[best_index] -= size;
    return best_index;
}

void deallocate_memory(int index, int size) {
    partitions[index] += size;
}

void display_partitions() {
    printf("Current partitions:\n");
    for (int i = 0; i < num_partitions; i++) {
        printf("%d: %d\n", i, partitions[i]);
    }
}

int main() {
    int choice, size, index;

    while (1) {
        printf("\n");
        printf("1. Add partition\n");
        printf("2. Allocate memory\n");
        printf("3. Deallocate memory\n");
        printf("4. Display partitions\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter partition size: ");
                scanf("%d", &size);

                if (num_partitions >= MAX_PARTITIONS) {
                    printf("Cannot add more partitions.\n");
                } else {
                    partitions[num_partitions] = size;
                    num_partitions++;
                }

                break;

            case 2:
                printf("Enter memory size: ");
                scanf("%d", &size);

                index = allocate_memory(size);

                if (index == -1) {
                    printf("Memory allocation failed.\n");
                } else {
                    printf("Allocated from partition %d.\n", index);
                }

                break;

            case 3:
                printf("Enter partition index: ");
                scanf("%d", &index);

                if (index < 0 || index >= num_partitions) {
                    printf("Invalid partition index.\n");
                } else {
                    printf("Enter memory size to deallocate: ");
                    scanf("%d", &size);

                    deallocate_memory(index, size);
                    printf("Deallocated from partition %d.\n", index);
                }

                break;

            case 4:
                display_partitions();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}

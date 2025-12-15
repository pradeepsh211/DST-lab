#include <stdio.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insertKey(int key) {
    int index = hashFunction(key);

    if (hashTable[index] == -1) {
        hashTable[index] = key;
    } else {
        int i = (index + 1) % TABLE_SIZE;
        while (i != index) {
            if (hashTable[i] == -1) {
                hashTable[i] = key;
                return;
            }
            i = (i + 1) % TABLE_SIZE;
        }
        printf("Hash table is full. Cannot insert %d\n", key);
    }
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1)
            printf("HT[%d] = %d\n", i, hashTable[i]);
        else
            printf("HT[%d] = EMPTY\n", i);
    }
}

int main() {
    int n, key;

    initHashTable();

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    printf("Enter %d employee keys (4-digit):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insertKey(key);
    }

    display();
    return 0;
}

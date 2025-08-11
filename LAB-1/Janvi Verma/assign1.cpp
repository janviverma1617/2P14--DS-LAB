#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void createArray(int arr[], int *size);
void displayArray(int arr[], int size);
void insertElement(int arr[], int *size);
void deleteElement(int arr[], int *size);
void linearSearch(int arr[], int size);
void removeDuplicates(int arr[], int *size);
void reverseArray(int arr[], int size);
void matrixMultiplication(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int c[MAX_SIZE][MAX_SIZE], int r1, int c1, int r2, int c2);
void transposeMatrix(int a[MAX_SIZE][MAX_SIZE], int t[MAX_SIZE][MAX_SIZE], int r, int c);
void sumRowsAndColumns(int arr[MAX_SIZE][MAX_SIZE], int r, int c);

int main() {
    int arr[MAX_SIZE], size = 0;
    int choice;
    
    do {
        printf("\n--- MENU ---\n");
        printf("1. CREATE\n");
        printf("2. DISPLAY\n");
        printf("3. INSERT\n");
        printf("4. DELETE\n");
        printf("5. LINEAR SEARCH\n");
        printf("6. REMOVE DUPLICATES\n");
        printf("7. REVERSE ARRAY\n");
        printf("8. MATRIX MULTIPLICATION\n");
        printf("9. TRANSPOSE MATRIX\n");
        printf("10. SUM OF ROWS AND COLUMNS\n");
        printf("11. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createArray(arr, &size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                insertElement(arr, &size);
                break;
            case 4:
                deleteElement(arr, &size);
                break;
            case 5:
                linearSearch(arr, size);
                break;
            case 6:
                removeDuplicates(arr, &size);
                break;
            case 7:
                reverseArray(arr, size);
                break;
            case 8: {
                int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], c[MAX_SIZE][MAX_SIZE];
                int r1, c1, r2, c2;
                printf("Enter rows and columns for first matrix: ");
                scanf("%d %d", &r1, &c1);
                printf("Enter rows and columns for second matrix: ");
                scanf("%d %d", &r2, &c2);
                if (c1 != r2) {
                    printf("Matrix multiplication not possible.\n");
                    break;
                }
                printf("Enter elements of first matrix:\n");
                for (int i = 0; i < r1; i++)
                    for (int j = 0; j < c1; j++)
                        scanf("%d", &a[i][j]);
                printf("Enter elements of second matrix:\n");
                for (int i = 0; i < r2; i++)
                    for (int j = 0; j < c2; j++)
                        scanf("%d", &b[i][j]);
                matrixMultiplication(a, b, c, r1, c1, r2, c2);
                break;
            }
            case 9: {
                int a[MAX_SIZE][MAX_SIZE], t[MAX_SIZE][MAX_SIZE];
                int r, c;
                printf("Enter rows and columns for matrix: ");
                scanf("%d %d", &r, &c);
                printf("Enter elements of matrix:\n");
                for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++)
                        scanf("%d", &a[i][j]);
                transposeMatrix(a, t, r, c);
                break;
            }
            case 10: {
                int arr[MAX_SIZE][MAX_SIZE], r, c;
                printf("Enter number of rows and columns: ");
                scanf("%d %d", &r, &c);
                printf("Enter elements of the array:\n");
                for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++)
                        scanf("%d", &arr[i][j]);
                sumRowsAndColumns(arr, r, c);
                break;
            }
            case 11:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 11);

    return 0;
}

void createArray(int arr[], int *size) {
    printf("Enter the number of elements: ");
    scanf("%d", size);
    printf("Enter the elements:\n");
    for (int i = 0; i < *size; i++) {
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int *size) {
    if (*size >= MAX_SIZE) {
        printf("Array is full. Cannot insert new element.\n");
        return;
    }
    int element, position;
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position to insert (0 to %d): ", *size);
    scanf("%d", &position);
    if (position < 0 || position > *size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
}

void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("Array is empty. Cannot delete element.\n");
        return;
    }
    int position;
    printf("Enter the position to delete (0 to %d): ", *size - 1);
    scanf("%d", &position);
    if (position < 0 || position >= *size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void linearSearch(int arr[], int size) {
    int element;
    printf("Enter the element to search: ");
    scanf("%d", &element);
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("Element found at index %d.\n", i);
            return;
        }
    }
    printf("Element not found.\n");
}

void removeDuplicates(int arr[], int *size) {
    int temp[MAX_SIZE], newSize = 0;
    for (int i = 0; i < *size; i++) {
        int j;
        for (j = 0; j < newSize; j++) {
            if (arr[i] == temp[j]) {
                break;
            }
        }
        if (j == newSize) {
            temp[newSize++] = arr[i];
        }
    }
    for (int i = 0; i < newSize; i++) {
        arr[i] = temp[i];
    }
    *size = newSize;
    printf("Duplicates removed. New size is %d.\n", *size);
}

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    printf("Array reversed.\n");
}

void matrixMultiplication(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int c[MAX_SIZE][MAX_SIZE], int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            c[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("Resultant matrix after multiplication:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int a[MAX_SIZE][MAX_SIZE], int t[MAX_SIZE][MAX_SIZE], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            t[j][i] = a[i][j];
        }
    }
    printf("Transposed matrix:\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
}

void sumRowsAndColumns(int arr[MAX_SIZE][MAX_SIZE], int r, int c) {
    int rowSum[MAX_SIZE] = {0}, colSum[MAX_SIZE] = {0};
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            rowSum[i] += arr[i][j];
            colSum[j] += arr[i][j];
        }
    }
    printf("Sum of each row:\n");
    for (int i = 0; i < r; i++) {
        printf("Row %d: %d\n", i, rowSum[i]);
    }
    printf("Sum of each column:\n");
    for (int j = 0; j < c; j++) {
        printf("Column %d: %d\n", j, colSum[j]);
    }
}

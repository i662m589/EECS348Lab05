#include <stdio.h>
#define SIZE 5
/*These are defined at the beginning to input the correct the correct dependencies into the code.*/
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
    int added_matrix[SIZE][SIZE];
    for (int a = 0; a < SIZE; a++) {
        for (int b = 0; b < SIZE; b++) {
            added_matrix[a][b] = m1[a][b] + m2[a][b];
            printf("%d ", added_matrix[a][b]);
        }
        printf("\n");
    }
}
/*This function takes in two matrices, creates a new blank matrix, appends the sum of both given matrices to each respective shot, and prints the new matrix.*/
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
    int mult_matrix[SIZE][SIZE];
    for (int r = 0; r < SIZE; r++) {
        for (int s = 0; s < SIZE; s++) {
            mult_matrix[r][s] = 0;
            for (int t = 0; t < SIZE; t++) {
                mult_matrix[r][s] = mult_matrix[r][s] + (m1[r][t] * m2[t][s]);
            }
            printf("%d ", mult_matrix[r][s]);
        }
        printf("\n");
    }
}
/*This function takes in two matrices, creates a new blank matrix, performs matrix multiplication for each location, and prints the result to the user.*/
void transposeMatrix(int matrix[SIZE][SIZE]) {
    int tran_matrix[SIZE][SIZE];
    for (int e = 0; e < SIZE; e++) {
        for (int f = 0; f < SIZE; f++) {
            tran_matrix[e][f] = matrix[f][e];
            printf("%d ", tran_matrix[e][f]);
        }
        printf("\n");
    }
}
/*This function takes in a matrix, transposes the inputted matrix and prints it to the user.*/
void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
/*This function takes in a matrix and prints out all the elements to the user.*/
int main() {
    int m1[SIZE][SIZE] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    int m2[SIZE][SIZE] = {{25, 24, 23, 22, 21}, {20, 19, 18, 17, 16}, {15, 14, 13, 12, 11}, {10, 9, 8, 7, 6}, {5, 4, 3, 2, 1}};
/*These variables are the matrices that will be used throughout the remainder of the program.*/
    printf("Addition of Matrix 1 and Matrix 2\n");
    addMatrices(m1,m2);
    printf("Multiplication of Matrix 1 and Matrix 2\n");
    multiplyMatrices(m1,m2);
/*These functions tell the user what matrix operation is happening and prints that matrix operation to the user.*/
    int choice1;
    printf("What matrix would you like to transpose?: ");
    scanf("%d", &choice1);
    if (choice1 == 1) {
        transposeMatrix(m1);
    }
    else if (choice1 == 2) {
        transposeMatrix(m2);
    }
    else {
        printf("Invalid Input\n");
    }
/*This code gets the users input to see what matrix they would like to transpose before transposing that matrix.*/
    int choice2;
    printf("What matrix would you like to print?: ");
    scanf("%d", &choice2);
    if (choice2 == 1) {
        printMatrix(m1);
    }
    else if (choice2 == 2) {
        printMatrix(m2);
    }
    else {
        printf("Invalid Input\n");
        
    }
/*This code gets the users input to see what matrix they would like to print before printing that matrix.*/
    return 0;
/*The main() function returns this value to end the program.*/
}
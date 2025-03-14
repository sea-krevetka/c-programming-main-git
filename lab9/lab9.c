#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int findMaxEli(int matrix[MAX_SIZE][MAX_SIZE], int N) {
    int maxtmp = matrix[0][0];
    int mi = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] > maxtmp) {
                maxtmp = matrix[i][j];
                mi = i;
            }
        }
    }
    return mi;
}

int findMaxElj(int matrix[MAX_SIZE][MAX_SIZE], int N) {
    int maxtmp = matrix[0][0];
    int mj = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] > maxtmp) {
                maxtmp = matrix[i][j];
                mj = j;
            }
        }
    }
    return mj;
}


int countZeros(int matrix[MAX_SIZE][MAX_SIZE], int N) {
    int cnt1 = 0;
    for (int i = 0; i < N; i++) {
        int cnt2 = 0;
        for (int j = 0; j < N; j++) { 
            if (matrix[i][j] == 0) {
                cnt2++;
            }
        }
       if (cnt2 > 0) {
            cnt1++;
        }
    }
    return cnt1;
}


void diagonalBackw(int matrix[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = N - 1; i >= 0; i--){
        for (int j=N-1; j>=0; j--){
            if (i==j){
                printf("%d ", matrix[i][j]);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N;
    
    printf("Type size of matrix: ");
    //scanf("%d", &N);
    
    int flaginput=0;
    while (flaginput == 0) {
        if (scanf("%d", &N) != 1) {
            printf("Invalid input.\n");
            printf("Type size of matrix: ");
            while (getchar() != '\n'); // Очистка буфера
            continue;
        }

        if (N > 0 && N <= MAX_SIZE) {
            flaginput = 1; 
        } else {
            printf("Number is not in valid range.\n");
            printf("Type size of matrix: ");
        }
    }



    if (N < 1 || N > MAX_SIZE) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    int flag = 0;
    printf("Fill matrix manually (1) or randomly (0)?\nChoose 1 or 0: ");
    scanf("%d", &flag);
    if (flag != 1 && flag != 0) {
        printf("Invalid type.\n");
        return 0;
    }

    int matrix[MAX_SIZE][MAX_SIZE];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (flag == 0) {
                matrix[i][j] = rand() % 100 + 0;
            } else {
                printf("Enter element [%d][%d]: ", i, j);
                scanf("%d", &matrix[i][j]);
            }
        }
    }


    int maxMatEli = findMaxEli(matrix, N);
    int maxMatElj = findMaxElj(matrix, N);
    
    

    int matrixB[MAX_SIZE][MAX_SIZE];
    for (int i = 0, bi = 0; i < N; i++) {
        if (i == maxMatEli) continue; // Пропускаем строку с максимальным элементом
        for (int j = 0, bj = 0; j < N; j++) {
            if (j == maxMatElj) continue; // Пропускаем столбец с максимальным элементом
            matrixB[bi][bj] = matrix[i][j];
            bj++;
        }
        bi++;
    }

    printf("Original Matrix:\n");
    printMatrix(matrix, N);

    printf("Matrix B:\n");
    printMatrix(matrixB, N - 1); 

    int strZeros = countZeros(matrixB, N - 1); 
    printf("Number of rows with zeros in matrix B: %d\n", strZeros);

    printf("Diagonal of matrix B in reverse order:\n");
    diagonalBackw(matrixB, N - 1); 


}

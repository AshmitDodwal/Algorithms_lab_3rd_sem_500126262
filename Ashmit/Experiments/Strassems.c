#include <stdio.h>

void split(int n, int matrix[n][n], int a[n/2][n/2], int b[n/2][n/2], int c[n/2][n/2], int d[n/2][n/2]) {
    int mid = n / 2;
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            a[i][j] = matrix[i][j];            
            b[i][j] = matrix[i][j + mid];        
            c[i][j] = matrix[i + mid][j];        
            d[i][j] = matrix[i + mid][j + mid];  
        }
    }
}

void add(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, int A[n][n], int B[n][n], int C[n][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int mid = n / 2;

    int a[mid][mid], b[mid][mid], c[mid][mid], d[mid][mid];
    int e[mid][mid], f[mid][mid], g[mid][mid], h[mid][mid];
    int m1[mid][mid], m2[mid][mid], m3[mid][mid], m4[mid][mid], m5[mid][mid], m6[mid][mid], m7[mid][mid];
    int temp1[mid][mid], temp2[mid][mid];

    split(n, A, a, b, c, d);
    split(n, B, e, f, g, h);

    add(mid, a, d, temp1);
    add(mid, e, h, temp2);
    strassen(mid, temp1, temp2, m1);

    add(mid, c, d, temp1);
    strassen(mid, temp1, e, m2);

    subtract(mid, f, h, temp2);
    strassen(mid, a, temp2, m3);

    subtract(mid, g, e, temp2);
    strassen(mid, d, temp2, m4);

    add(mid, a, b, temp1);
    strassen(mid, temp1, h, m5);

    subtract(mid, c, a, temp1);
    add(mid, e, f, temp2);
    strassen(mid, temp1, temp2, m6);

    subtract(mid, b, d, temp1);
    add(mid, g, h, temp2);
    strassen(mid, temp1, temp2, m7);

    add(mid, m1, m4, temp1);
    subtract(mid, temp1, m5, temp1);
    add(mid, temp1, m7, C[0]); // C11

    add(mid, m3, m5, C[0] + mid); // C12

    add(mid, m2, m4, C[mid]); // C21

    add(mid, m1, m3, temp1);
    subtract(mid, temp1, m2, temp1);
    add(mid, temp1, m6, C[mid] + mid); // C22
}

int main() {
    int n = 4; 
    int A[4][4] = {
        {12, 34, 5, 2},
        {22, 10, 1, 0},
        {1, 2, 3, 4},
        {0, 1, 4, 5}
    };
    int B[4][4] = {
        {3, 4, 2, 1},
        {2, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 2, 3}
    };
    int C[4][4] = {0};

    strassen(n, A, B, C);

    printf("Product achieved using Strassen's algorithm:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
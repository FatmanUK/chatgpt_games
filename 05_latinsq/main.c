#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9

int main() {
    srand(time(0));
    int square[N][N];
    int i, j, k, temp;
    int row[N], col[N], diag[2];

    // Initialize the square with values from 1 to N
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            square[i][j] = i * N + j + 1;
        }
    }

    // Shuffle the rows
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            k = rand() % N;
            temp = square[i][j];
            square[i][j] = square[i][k];
            square[i][k] = temp;
        }
    }

    // Shuffle the columns
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            k = rand() % N;
            temp = square[j][i];
            square[j][i] = square[k][i];
            square[k][i] = temp;
        }
    }

    // Check if the square is a Latin Square
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            row[j] = 0;
            col[j] = 0;
        }
        diag[0] = diag[1] = 0;
        for (j = 0; j < N; j++) {
            if (++row[square[i][j] - 1] > 1) {
                printf("Not a Latin Square\n");
                return 0;
            }
            if (++col[square[j][i] - 1] > 1) {
                printf("Not a Latin Square\n");
                return 0;
            }
            if (i == j) {
                if (++diag[0] > 1) {
                    printf("Not a Latin Square\n");
                    return 0;
                }
            }
            if (i + j == N - 1) {
                if (++diag[1] > 1) {
                    printf("Not a Latin Square\n");
                    return 0;
                }
            }
        }
    }

    // Print the square
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", square[i][j]);
        }
        printf("\n");
    }

    return 0;
}


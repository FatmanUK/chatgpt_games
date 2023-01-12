#include <stdio.h>
#include <stdbool.h>

#define N 9

bool isSafe(int square[N][N], int row, int col, int num) {
    // Check if the number already exists in the same row or column
    for (int i = 0; i < N; i++) {
        if (square[row][i] == num || square[i][col] == num) {
            return false;
        }
    }
    return true;
}

bool solve(int square[N][N], int row, int col) {
    if (row == N && col == 0) {
        return true;
    }

    if (col == N) {
        row++;
        col = 0;
    }

    // Try all numbers from 1 to N
    for (int num = 1; num <= N; num++) {
        if (isSafe(square, row, col, num)) {
            square[row][col] = num;

            if (solve(square, row, col + 1)) {
                return true;
            }

            // Backtrack
            square[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int square[N][N] = { 0 };

    if (solve(square, 0, 0)) {
        // Print the square
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", square[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists");
    }

    return 0;
}


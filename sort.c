#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void sort(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        printf("n/a");
        return 0;
    }
    
    sort(data, n);
    output(data, n);
    
    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n != NMAX) {
        return 1;
    }
    
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
}

void sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
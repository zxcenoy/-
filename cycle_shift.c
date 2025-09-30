#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int *shift);
void output(int *a, int n);
void cycle_shift(int *a, int n, int shift);

int main() {
    int n, shift, data[NMAX];
    if (input(data, &n, &shift)) {
        printf("n/a");
        return 0;
    }
    
    cycle_shift(data, n, shift);
    output(data, n);
    
    return 0;
}

int input(int *a, int *n, int *shift) {
    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) {
        return 1;
    }
    
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }
    
    if (scanf("%d", shift) != 1) {
        return 1;
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

void cycle_shift(int *a, int n, int shift) {
    shift = shift % n;
    if (shift < 0) {
        shift = n + shift;
    }

    void reverse(int *arr, int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    
    if (shift > 0) {
        reverse(a, 0, shift - 1);
        reverse(a, shift, n - 1);
        reverse(a, 0, n - 1);
    }
}
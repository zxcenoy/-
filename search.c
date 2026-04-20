#include <stdio.h>
#include <math.h>
#define NMAX 30

int input(int *a, int *n);
void output(int result);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
int search(int *a, int n);

int main()
{
    int n, data[NMAX];
    if (input(data, &n)) {
        printf("n/a");
        return 0;
    }
    
    int result = search(data, n);
    output(result);
    
    return 0;
}

int input(int *a, int *n)
{
    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) {
        return 1;
    }
    
    for(int i = 0; i < *n; i++)
    {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }
    return 0;
}

void output(int result)
{
    printf("%d\n", result);
}

double mean(int *a, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / n;
}

double variance(int *a, int n)
{
    double mean_val = mean(a, n);
    double sum_sq = 0;
    
    for (int i = 0; i < n; i++) {
        double diff = a[i] - mean_val;
        sum_sq += diff * diff;
    }
    
    return sum_sq / n;
}

int search(int *a, int n)
{
    double mean_val = mean(a, n);
    double variance_val = variance(a, n);
    double upper_bound = mean_val + 3 * sqrt(variance_val);
    
    for (int i = 0; i < n; i++) {
        int current = a[i]; 
        if (current != 0 && 
            current % 2 == 0 && 
            current >= mean_val && 
            current <= upper_bound) {
            return current;
        }
    }
    
    return 0;
}
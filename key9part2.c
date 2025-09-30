#include <stdio.h>

#define LEN 100

void input(int *buffer, int *length);
void output(int *buffer, int length);
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
int compare(int *buff1, int len1, int *buff2, int len2);

int main()
{
    int num1[LEN], num2[LEN], len1, len2;
    
    input(num1, &len1);
    input(num2, &len2);
    
    if (len1 == -1 || len2 == -1) {
        printf("n/a");
        return 0;
    }
    
    int sum_result[LEN + 1], sum_len;
    int sub_result[LEN], sub_len;
    
    sum(num1, len1, num2, len2, sum_result, &sum_len);
    output(sum_result, sum_len);
    printf("\n");
    
    if (compare(num1, len1, num2, len2) >= 0) {
        sub(num1, len1, num2, len2, sub_result, &sub_len);
        output(sub_result, sub_len);
    } else {
        printf("n/a");
    }
    
    return 0;
}

void input(int *buffer, int *length)
{
    *length = 0;
    int digit;
    
    while (scanf("%d", &digit) == 1 && *length < LEN) {
        if (digit < 0 || digit > 9) {
            *length = -1; 
            return;
        }
        buffer[(*length)++] = digit;
    }
    
    if (*length == 0) {
        *length = -1;
    }
}

void output(int *buffer, int length)
{
    for (int i = 0; i < length; i++) {
        printf("%d", buffer[i]);
        if (i < length - 1) {
            printf(" ");
        }
    }
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length)
{
    int carry = 0;
    int i = len1 - 1, j = len2 - 1, k = 0;
    
    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? buff1[i--] : 0;
        int digit2 = (j >= 0) ? buff2[j--] : 0;
        
        int sum = digit1 + digit2 + carry;
        result[k++] = sum % 10;
        carry = sum / 10;
    }
    
    *result_length = k;
    
    for (int i = 0; i < k / 2; i++) {
        int temp = result[i];
        result[i] = result[k - 1 - i];
        result[k - 1 - i] = temp;
    }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length)
{
    int borrow = 0;
    int i = len1 - 1, j = len2 - 1, k = 0;
    
    while (i >= 0) {
        int digit1 = buff1[i--];
        int digit2 = (j >= 0) ? buff2[j--] : 0;
        
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        result[k++] = diff;
    }
    
    *result_length = k;
    
    while (*result_length > 1 && result[*result_length - 1] == 0) {
        (*result_length)--;
    }
    
    for (int i = 0; i < *result_length / 2; i++) {
        int temp = result[i];
        result[i] = result[*result_length - 1 - i];
        result[*result_length - 1 - i] = temp;
    }
}

int compare(int *buff1, int len1, int *buff2, int len2)
{
    if (len1 != len2) {
        return len1 - len2;
    }
    
    for (int i = 0; i < len1; i++) {
        if (buff1[i] != buff2[i]) {
            return buff1[i] - buff2[i];
        }
    }
    
    return 0; 
}
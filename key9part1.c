#include <stdio.h>
#define NMAX 10

void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers);

/*------------------------------------
	Функция получает массив данных 
	через stdin.
	Выдает в stdout особую сумму
	и сформированный массив 
	специальных элементов
	(выбранных с помощью найденной суммы):
	это и будет частью ключа
-------------------------------------*/
int main()
{
    int length, buffer[NMAX];
    input(buffer, &length);
    
    int sum = sum_numbers(buffer, length);
    if (sum == 0) {
        printf("n/a");
        return 0;
    }
    
    int numbers[NMAX];
    int count = find_numbers(buffer, length, sum, numbers);
    
    if (count == 0) {
        printf("n/a");
        return 0;
    }
    
    printf("%d\n", sum);
    output(numbers, count);
    
    return 0;
}

void input(int *buffer, int *length)
{
    if (scanf("%d", length) != 1 || *length <= 0 || *length > NMAX) {
        *length = -1; // Помечаем ошибку
        return;
    }
    
    for (int i = 0; i < *length; i++) {
        if (scanf("%d", &buffer[i]) != 1) {
            *length = -1; // Помечаем ошибку
            return;
        }
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

/*------------------------------------
	Функция должна находить
	сумму четных элементов 
	с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length)
{
    int sum = 0;
    int has_even = 0;
    
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum += buffer[i];
            has_even = 1;
        }
    }
    
    return has_even ? sum : 0;
}

/*------------------------------------
	Функция должна находить
	все элементы, на которые нацело
	делится переданное число и
	записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int* buffer, int length, int number, int* numbers)
{
    int count = 0;
    
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[count] = buffer[i];
            count++;
        }
    }
    
    return count;
}
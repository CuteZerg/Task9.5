#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void swap_rows(double **a, int r1, int r2, int n)
{
    int tmp;
    for (int j = 0; j < n+1; j++)
    {
        tmp = a[r1][j];
        a[r1][j] = a[r2][j];
        a[r2][j] = tmp;
    }
}

void prepare(double **a, int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if( (a[j][j] == 0) && (a[i][j] != 0) )
            {
                swap_rows(a, j, i, n);
            }
        }
    }
}

void print_arr(double **a, int n)
{
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            printf("%.2lf ", a[i][j]);
        }
        printf("\n");
    }
}


void upper_triangle(double **a, int n, int k)
{
    double coef;
    while (k >= 1)
    {
        for (int i = n - k; i < n; i++)
        {
            if (a[n-k-1][n-k-1] != 0)
                coef = a[i][n-k-1]/a[n-k-1][n-k-1];
            else
                continue;
            for (int j = 0; j < n+1; j++)
            {
                a[i][j] -= a[n-k-1][j]*coef;
            }
        }
        k--;
    }
}

void lower_triangle(double **a, int n, int k)
{
    double coef;
    while (k >= 1)
    {
        for (int i = k-1; i >= 0; i--)
        {
            if (a[k][k] != 0)
                coef = a[i][k]/a[k][k];
            else
                continue;
            for (int j = 0; j < n + 1; j++)
            {
                a[i][j] -= a[k][j]*coef;
            }
        }
        k--;
    }
}


int main()
{
    double **a;
    int n;
    setlocale(LC_ALL, "Rus");

    printf("¬ведите количество переменных: ");
    scanf("%d", &n);

    a = (double**)malloc(n * sizeof(double*));


    for (int i = 0; i < n; i++)
    {
        a[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j < n+1; j++)
        {
          printf("a[%d][%d] = ", i, j);
          scanf("%lf", &a[i][j]);
        }
    }
    prepare(a, n);
    upper_triangle(a, n, n-1);
    lower_triangle(a, n, n-1);

    printf("\n");
    for(int i = 0; i < n; i++)
    {
        printf("x%d = %lf\n", i+1, a[i][n]/a[i][i]);
    }

    return 0;
}

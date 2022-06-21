#include <stdio.h>
#define SIZE 10
void sort(int p[], int at[], int bt[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i); j++)
        {
            if (at[j] > at[j + 1])
            {
                int temp = p[j + 1];
                p[j + 1] = p[j];
                p[j] = temp;

                temp = at[j + 1];
                at[j + 1] = at[j];
                at[j] = temp;

                temp = bt[j + 1];
                bt[j + 1] = bt[j];
                bt[j] = temp;
            }
        }
    }
}

int main()
{
    int p[SIZE], at[SIZE], bt[SIZE], ct[SIZE], tat[SIZE], wt[SIZE], i, j, temp = 0, n;
    float awt = 0, atat = 0;
    printf("Enter No of Proccess: ");
    scanf("%d", &n);
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter Process %d ID: ", i + 1);
        scanf("%d", &p[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter Process %d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter Process %d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }
    sort(p, at, bt, n);
    ct[0] = at[0] + bt[0];
    for (i = 1; i < n; i++)
    {
        temp = 0;
        if (ct[i - 1] < at[i])
        {
            temp = at[i] - ct[i - 1];
        }
        ct[i] = ct[i - 1] + bt[i] + temp;
    }
    printf("\nP\t AT\t BT\t CT\t TAT\t WT\t RT");
    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        atat += tat[i];
        awt += wt[i];
    }
    atat = atat / n;
    awt = awt / n;
    for (i = 0; i < n; i++)
    {
        printf("\nP%d\t %d\t %d\t %d \t %d \t %d \t %d", p[i], at[i], bt[i], ct[i], tat[i], wt[i], wt[i]);
    }
    printf("\n");
    printf("\nAverage Turn Around Time is: %.2f", atat);
    printf("\nAverage Waiting Time is: %.2f", awt);
    return 0;
}
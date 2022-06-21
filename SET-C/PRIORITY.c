#include <stdio.h>
struct process
{
    int WT, AT, BT, TAT, PT;
};

struct process a[10];

int main()
{
    int n, temp[10], t, count = 0, short_p;
    float total_WT = 0, total_TAT = 0, Avg_WT, Avg_TAT;
    printf("Enter number of Process: ");
    scanf("%d", &n);
    printf("Enter Arrival Time, Burst Time and Priority\n");
    printf("AT BT PT\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &a[i].AT, &a[i].BT, &a[i].PT);
        temp[i] = a[i].BT;
    }

    a[9].PT = 10000;

    for (t = 0; count != n; t++)
    {
        short_p = 9;
        for (int i = 0; i < n; i++)
        {
            if (a[short_p].PT > a[i].PT && a[i].AT <= t && a[i].BT > 0)
            {
                short_p = i;
            }
        }

        a[short_p].BT = a[short_p].BT - 1;

        if (a[short_p].BT == 0)
        {
            count++;
            a[short_p].WT = t + 1 - a[short_p].AT - temp[short_p];
            a[short_p].TAT = t + 1 - a[short_p].AT;

            total_WT = total_WT + a[short_p].WT;
            total_TAT = total_TAT + a[short_p].TAT;
        }
    }

    Avg_WT = total_WT / n;
    Avg_TAT = total_TAT / n;

    printf("\nID\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\n", i + 1, a[i].WT, a[i].TAT);
    }

    printf("Avg Waiting Time: %.2f\n", Avg_WT);
    printf("Avg Turn Around Time: %.2f\n", Avg_TAT);

    return 0;
}

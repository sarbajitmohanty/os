#include <stdio.h>
int main()
{
    int rF[10], pF = 0, m, n, s, pages, frames;
    printf("\nEnter the number of Pages: ");
    scanf("%d", &pages);
    printf("\nEnter reference string values: \n");
    for (m = 0; m < pages; m++)
    {
        printf("Value No. [%d]: ", m + 1);
        scanf("%d", &rF[m]);
    }
    printf("\nWhat are the total number of frames: ");
    scanf("%d", &frames);
    int temp[frames];
    for (m = 0; m < frames; m++)
    {
        temp[m] = -1;
    }
    for (m = 0; m < pages; m++)
    {
        s = 0;
        for (n = 0; n < frames; n++)
        {
            if (rF[m] == temp[n])
            {
                s++;
                pF--;
            }
        }
        pF++;
        if ((pF <= frames) && (s == 0))
        {
            temp[m] = rF[m];
        }
        else if (s == 0)
        {
            temp[(pF - 1) % frames] = rF[m];
        }
        printf("\n");
        for (n = 0; n < frames; n++)
        {
            printf("%d\t", temp[n]);
        }
    }
    printf("\n\nTotal Page Faults: %d\n", pF);
    return 0;
}
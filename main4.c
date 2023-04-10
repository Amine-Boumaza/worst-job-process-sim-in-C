#include <stdio.h>
#include <stdlib.h>

int main()
{
    int partition[12] = {10, 40, 20, 15, 10, 20, 30, 80, 10, 45, 50, 30};
    int partitionUsed[12] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1};
    int processes = 5;
    int processCount[] = {20, 40, 15, 30, 50};

    int i, j, maxProcessNum;

    for (i = 0; i < processes; i++)
    {
        int min_partition = 1000;
        maxProcessNum = -1;
        for (j = 0; j < 12; j++)
        {
            if (partition[j] >= processCount[i] && partition[j] < min_partition && partitionUsed[j] != 1)
            {
                min_partition = partition[j];
                maxProcessNum = j;
            }
        }
        if (maxProcessNum != -1)
        {
            partition[maxProcessNum] -= processCount[i];

            printf("%d \t partition %d \t remaining %d\n", processCount[i], maxProcessNum + 1, partition[maxProcessNum]);
        }
        else
        {
            printf("%d\t not allocated\n", processCount[i]);
        }
    }
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Get number of partitions
    int nb_partition;
    printf("Enter number of partitions: ");
    scanf("%d", &nb_partition);

    // Get partition size and used/unused status
    int partitions[nb_partition], parti_used[nb_partition];
    for (int i = 0; i < nb_partition; i++)
    {
        printf("Enter size of partition %d: ", i + 1);
        scanf("%d", &partitions[i]);

        printf("Is partition %d used? (1 for used, 0 for unused): ", i + 1);
        scanf("%d", &parti_used[i]);
    }

    // Get number of processes
    int process;
    printf("Enter number of processes: ");
    scanf("%d", &process);

    // Get process size
    int process_size[process];
    for (int i = 0; i < process; i++)
    {
        printf("Enter size of process %d: ", i + 1);
        scanf("%d", &process_size[i]);
    }

    // Perform best fit allocation
    for (int i = 0; i < process; i++)
    {
        int min_p = 1000;
        int max_pn = -1;    
        for (int j = 0; j < nb_partition; j++)
        {
            if (partitions[j] >= process_size[i] && partitions[j] < min_p && parti_used[j] != 1)
            {
                min_p = partitions[j];
                max_pn = j;
            }
        }
        if (max_pn != -1)
        {
            partitions[max_pn] -= process_size[i];
            parti_used[max_pn] = 1;
            printf("%d \t partition %d \t remaining %d\n", process_size[i], max_pn + 1, partitions[max_pn]);
        }
        else
        {
            printf("%d\t not allocated\n", process_size[i]);
        }
    }

    return 0;
}

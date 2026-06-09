C语言：

#include <stdio.h>
#include <stdlib.h>

void myqsort(int *array, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int i = left;
    int j = right;
    int k = array[left];
    while (i != j)
    {
        while (array[j] > k && i != j)
            j--;

        if (i == j)
            break;
        int temp = array[j];
        array[j] = array[i];
        array[i++] = temp;

        while (array[i] <= k && i != j)
            i++;
        if (i == j)
            break;
        temp = array[i];
        array[i] = array[j];
        array[j--] = temp;
    }
    myqsort(array, left, i - 1);
    myqsort(array, j + 1, right);
}

int smallestDistancePair(int *nums, int numsSize, int k)
{
    myqsort(nums, 0, numsSize - 1);

    int low = 0;
    int high = nums[numsSize - 1] - nums[0];

    while (low < high)
    {
        int count = 0;
        int mid = low + (high - low) / 2;
        for (int i = 0; i < numsSize - 1; i++)
        {
            int j = i + 1;

            while (nums[j] - nums[i] <= mid && j < numsSize)
            {
                j++;
            }

            count += j - i - 1;
        }

        if (count < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return low;
}

int main()
{
    // int a[500] = {
    //     2, 2, 0, 1, 0, 1, 2, 0, 2, 1, 1, 1, 1, 0, 1, 2, 1, 1, 1, 2, 1, 2, 1, 0,
    //     1, 0, 1, 1, 0, 2, 1, 0, 0, 2, 2, 1, 1, 1, 2, 2, 1, 0, 0, 0, 2, 0, 0, 0,
    //     0, 0, 1, 0, 1, 2, 2, 2, 2, 2, 2, 1, 1, 0, 1, 0, 1, 1, 1, 1, 2, 1, 1, 2,
    //     2, 2, 0, 1, 2, 2, 2, 0, 0, 2, 0, 1, 2, 2, 1, 2, 0, 2, 1, 0, 0, 2, 1, 1,
    //     0, 1, 0, 1, 0, 0, 0, 1, 1, 2, 0, 0, 1, 2, 2, 2, 2, 2, 2, 0, 2, 1, 1, 1,
    //     1, 1, 2, 0, 2, 2, 2, 0, 2, 0, 1, 0, 1, 2, 1, 0, 1, 2, 1, 2, 1, 2, 0, 2,
    //     0, 1, 0, 1, 2, 2, 1, 2, 2, 1, 0, 0, 1, 2, 1, 1, 0, 0, 2, 1, 0, 2, 1, 2,
    //     0, 0, 1, 0, 2, 0, 1, 2, 2, 2, 1, 2, 0, 2, 2, 2, 2, 2, 0, 0, 0, 1, 0, 2,
    //     0, 0, 1, 1, 0, 0, 2, 2, 1, 0, 0, 0, 2, 0, 1, 1, 1, 2, 1, 1, 2, 1, 1, 0,
    //     1, 0, 1, 1, 1, 2, 0, 0, 2, 2, 2, 1, 1, 1, 2, 2, 2, 0, 1, 0, 0, 0, 0, 1,
    //     0, 2, 2, 0, 2, 2, 1, 1, 1, 2, 1, 1, 1, 0, 2, 0, 2, 1, 1, 2, 2, 1, 1, 2,
    //     0, 0, 2, 1, 2, 0, 1, 1, 1, 2, 2, 0, 1, 2, 2, 2, 1, 1, 0, 1, 0, 0, 1, 2,
    //     1, 1, 0, 1, 0, 2, 2, 2, 0, 1, 1, 0, 1, 0, 1, 2, 2, 2, 1, 1, 0, 1, 0, 0,
    //     2, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 1,
    //     0, 0, 0, 1, 1, 2, 2, 1, 2, 2, 0, 2, 1, 0, 2, 1, 2, 0, 1, 2, 1, 2, 2, 2,
    //     2, 2, 0, 0, 1, 0, 0, 2, 2, 0, 1, 0, 0, 0, 2, 1, 0, 1, 2, 1, 1, 0, 0, 1,
    //     1, 0, 0, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 2, 0, 1, 1, 2, 1, 0, 0,
    //     0, 2, 2, 1, 2, 2, 0, 0, 1, 0, 1, 0, 0, 1, 2, 0, 0, 0, 1, 1, 0, 0, 1, 0,
    //     0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 1, 2, 1, 1, 1, 2, 2, 0, 2, 1, 0, 2,
    //     1, 0, 2, 1, 1, 0, 2, 0, 2, 1, 0, 0, 0, 1, 1, 0, 1, 0, 2, 2, 2, 1, 2, 0,
    //     1, 2, 0, 0, 0, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 0, 1, 0, 0, 1};
    // int result = smallestDistancePair(a, 500, 62500);
    // myqsort(a, 0, 499);
    // for (int i = 0; i < 500; i++) {
    //   printf("%d,", a[i]);
    // }
    // printf("\n");

    int a[3] = {62, 100, 4};
    int result = smallestDistancePair(a, 3, 2);
    printf("result is %d\n", result);
    return 1;
}
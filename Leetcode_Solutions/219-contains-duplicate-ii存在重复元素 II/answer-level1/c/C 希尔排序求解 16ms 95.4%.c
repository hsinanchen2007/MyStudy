```
void shellsort(int* nums, int* posi, int numsSize)
{
    int step, i, j;
    for (step = numsSize / 2; step > 0; step /= 2)
    {
        for (i = step; i < numsSize; i++)
        {
            int numbtmp = nums[i];
            int positmp = posi[i];
            for (j = i - step; j >= 0 && numbtmp > nums[j]; j -= step)
            {
                nums[j + step] = nums[j];
                posi[j + step] = posi[j];
            }
            nums[j + step] = numbtmp;
            posi[j + step] = positmp;
        }
    }
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k)
{
    if (0 == numsSize || 0 == k) return false;
    int* posi = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
        posi[i] = i;
    shellsort(nums, posi, numsSize);
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == nums[i + 1] && posi[i + 1] - posi[i] <= k)
            return true;
    }
    return false;
}
```

建立两个数组，分别存储数字和下标，做法类似题目217

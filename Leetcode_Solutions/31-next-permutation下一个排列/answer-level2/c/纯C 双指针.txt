### 解题思路
纯C 双指针 左右指针

### 代码

```c
static int comp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

void nextPermutation(int* nums, int numsSize){
    if (NULL == nums || 0 == numsSize)
    {
        return;
    } 

    int left = numsSize - 2; // 从倒数第二个开始
    int right = 0;
    int temp = 0;

    while (left >= 0)
    {
        if (nums[left] < nums[left + 1]) // 往右比较
        {
            break;
        }

        left--;
    }

    if (-1 == left) // 如果本来就是逆序的
    {   
        return qsort(nums, numsSize, sizeof(int), comp);
    }

    for (right = left + 1; right <= numsSize - 1 && nums[left] < nums[right]; right++)
    {
        NULL;
    }

    temp = nums[left];
    nums[left] = nums[right - 1];
    nums[right - 1] = temp;

    qsort(nums + left + 1, numsSize - 1 - left, sizeof(int), comp);
}
```
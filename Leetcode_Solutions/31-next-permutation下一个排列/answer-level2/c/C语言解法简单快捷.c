![image.png](https://pic.leetcode-cn.com/577df264986658197cbba17b3552f0425eee56e67a3626469f4e8432994d00de-image.png)


```
void nextPermutation(int* nums, int numsSize) 
{
    if (numsSize <= 1) {
        return;
    }

    // 从后往前找
    int i = numsSize - 2;
    int j = numsSize - 1;
    int k = numsSize - 1;
    int temp = 0;

    // find: A[i] < A[j]
    while ((i >= 0) && (nums[i] >= nums[j])) {
        i--;
        j--;
    }

    // 不是最后一个排列
    if (i >= 0) {
        // 找到 A[i] < A[k]
        while (nums[i] >= nums[k]) {
            k--;
        }
        // 交换A[i]和A[k]
        temp = nums[i];
        nums[i] = nums[k];
        nums[k] = temp;
    }

    // resver A[j, end]
    for (i = j, j = numsSize - 1; i < j; i++, j--) {
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    return;
}
```

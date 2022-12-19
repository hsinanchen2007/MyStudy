### 解题思路
纯C 三次反转

### 代码

```c
static void reverse(int* nums, int numsSize, int start, int end)
{
    int temp = 0;

    while (start < end)
    {
        temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++, end--;
    }
}

void rotate(int* nums, int numsSize, int k){
    k = k % numsSize;

    reverse(nums, numsSize, 0, numsSize - 1);
    reverse(nums, numsSize, 0, k - 1);
    reverse(nums, numsSize, k, numsSize - 1);
}
```
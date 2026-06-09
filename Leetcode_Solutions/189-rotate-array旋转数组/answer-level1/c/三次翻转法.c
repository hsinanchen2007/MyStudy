### 解题思路

### 代码

```c
void reverse(int* nums, int numsSize){
    int i, temp;
    for (i = 0; i < numsSize / 2; i++)
    {
        temp = nums[i];
        nums[i] = nums[numsSize - i - 1];
        nums[numsSize - i - 1] = temp;
    }
}

void rotate(int* nums, int numsSize, int k){
    k %= numsSize;
    reverse(nums, numsSize);
    reverse(nums, k);
    reverse(nums + k, numsSize - k);
}
```
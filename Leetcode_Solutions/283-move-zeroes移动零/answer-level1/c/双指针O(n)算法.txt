### 解题思路

### 代码

```c
void moveZeroes(int* nums, int numsSize){
    int i, j;
    for (i = 0, j = 0; i < numsSize; i++)
    {
        if (nums[i] != 0) nums[j++] = nums[i];
    }
    memset(&nums[j], 0, sizeof(int) * (numsSize - j));
}
```
### 解题思路
先快速排序，再判定

### 代码

```c
int comp(const void *a, const void *b) 
{
    return *(int *)a - *(int *)b;
}
bool containsDuplicate(int* nums, int numsSize){
    int i, j;
    int tmp;
    if (numsSize == 0) {
        return false;
    }
    qsort(nums, numsSize, sizeof(int), comp);
    for (i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }
    return false;
}
```
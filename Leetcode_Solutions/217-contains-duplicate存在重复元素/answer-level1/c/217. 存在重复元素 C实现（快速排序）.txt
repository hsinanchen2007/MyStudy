### 解题思路
此处撰写解题思路

### 代码

```c
int Cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

bool containsDuplicate(int* nums, int numsSize){
    if (!nums || numsSize <= 0) {
        return false;
    }
    qsort(nums, numsSize, sizeof(int), Cmp);
    int res = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] == nums[i]) {
            return true;
        }
    }
    return false;
}
```
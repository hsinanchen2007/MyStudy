### 解题思路
此处撰写解题思路

### 代码

```c
int comFun(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}
int findDuplicate(int* nums, int numsSize){
    int i = 0;
    if(numsSize == 0) {
        return 0;
    }
    if(numsSize == 1) {
        return nums[0];
    }
    qsort(nums, numsSize, sizeof(int), comFun);
    int tmp = 0;
    while(i < numsSize-1) {
        tmp = nums[i]^nums[i+1];
        if(tmp == 0) {
            break;
        }
        i++;
    }
    return nums[i];
}
```
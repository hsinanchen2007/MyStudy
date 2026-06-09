```
//排序之后双指针进行窗口移动。
int maxValue(int a, int b) 
{
    return a >= b ? a : b;
}
int comp(const void* a, const void* b) 
{
    return *(int *)a - *(int *)b;
}
int findLHS(int* nums, int numsSize){
    if(nums == NULL || numsSize == 0) {
        return 0;
    }
    int res = 0;
    int begin = 0;
    qsort(nums, numsSize, sizeof(nums[0]), comp);
    for(int end = 0; end < numsSize; end++) {
        int count = 0;
        while(nums[end] - nums[begin] > 1) {
            begin++;
        }
        if(nums[end] - nums[begin] == 1) {
            res = maxValue(res, end - begin + 1);
        }
    }
    return res;
}
```

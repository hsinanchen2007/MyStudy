### 解题思路
先qsort排序，再异或运算，将不为0的取出即可。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int comFun(const void *a, const void *b) 
 {
     return ((*(int*)a) > (*(int*)b) ? 1 : 0);
 }
int* singleNumber(int* nums, int numsSize, int* returnSize){
    int *res = (int*)malloc(2*sizeof(int));
    int tmp = 0;
    int i = 0;
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), comFun);
    while(i < numsSize-1) {
        tmp = nums[i]^nums[i+1];
        if(tmp == 0) {
            i += 2;
        } else {
            res[*returnSize] = nums[i];
            (*returnSize)++;
            i++;
        }
    }
    if(i == numsSize - 1) {
       res[*returnSize] = nums[i];
       (*returnSize)++; 
    }
    return res;
}
```
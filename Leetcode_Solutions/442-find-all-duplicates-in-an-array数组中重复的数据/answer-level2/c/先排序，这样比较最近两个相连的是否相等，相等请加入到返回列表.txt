### 解题思路
先排序，重复加入返回列表


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int int_cmp(void* a, void* b) 
 {
     int *a1 = (int *)a;
     int *b1 = (int *)b;  
     return (*a1 - *b1);   
 }
 int* findDuplicates(int* nums, int numsSize, int* returnSize){
    int* ret;
    int i;
    int k = 0;
    ret = malloc(sizeof(int) * (numsSize + 1));
    memset(ret, 0, sizeof(int) * (numsSize + 1));
    qsort(nums,numsSize,sizeof(int),int_cmp);
    if (numsSize <= 1 ) {
        *returnSize = 0;
        return ret;
    }
    int pre = nums[0];
    for (i = 1; i < numsSize; i++) {
        //printf("%d %d\n",pre,nums[i]);
        if (pre == nums[i]) {
            if (ret[k] != nums[i])
            ret[k++] = nums[i];
        } else {
            pre = nums[i];
        }
    }
    *returnSize = k;
    return ret;
}
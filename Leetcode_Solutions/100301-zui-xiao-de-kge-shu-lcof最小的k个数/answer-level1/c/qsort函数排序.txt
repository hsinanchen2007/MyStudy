### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(void *p,void *q){
    return *(int*)p - *(int*)q;
} 

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    qsort(arr,arrSize,sizeof(int),cmp);
    *returnSize = arrSize > k ? k: arrSize;
    int *ret = malloc(*returnSize * sizeof(int));
    memcpy(ret,arr,*returnSize * sizeof(int));
    return ret;
}
```
### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(void* a, void* b){
    return *(int*)a - *(int*)b;
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    if(arrSize == 0)
        return NULL;
    qsort(arr, arrSize, sizeof(int), cmp);
    int* ret = (int*)malloc(k*sizeof(int));
    *returnSize = k;
    int i = 0;
    for(i = 0;i < k; i++){
        ret[i] = arr[i];
    }
    return ret;
}
```
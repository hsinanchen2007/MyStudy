### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int cmp(void *a, void *b) {
    return  *((int *)a) - *((int *)b);
 }
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    if (arrSize <= k) {
        *returnSize = arrSize;
        return arr;
    }
    qsort(arr, arrSize, sizeof(int), cmp);
    *returnSize = k;
    return arr;
    
}
```
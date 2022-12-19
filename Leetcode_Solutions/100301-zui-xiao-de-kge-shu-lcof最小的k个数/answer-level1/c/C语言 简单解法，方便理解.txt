
### 这类题用现成的库感觉没意思了，不过省时间拿积分

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int cmp(void *a, void *b)
 {
     return *(int *)a  - *(int *)b;
 }
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    
    qsort(arr, arrSize, sizeof(int), cmp);  // 从小到大排序

    int *ret = (int *) malloc( sizeof(int) * k );
    *returnSize = k;    // returnSize 这个参数感觉没什么意义，原样返回

    memcpy(ret, arr, k * (sizeof(int))); // 前K个取出来返回

    return ret;
}
```

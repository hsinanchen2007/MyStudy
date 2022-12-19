### 解题思路
1.首先对A数组进行从小到大的排序
2.便利数组B，只要数组A的元素大于B，就将A元素写入结果中，这样就可以保证A中剩余的元素中，刚好比B这个元素大；
3.如果剩余的A元素都小于B当前元素，则将数组中最小的元素写入结果中；
就是田忌赛马。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define USEDMAX -1
int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int* advantageCount(int* A, int ASize, int* B, int BSize, int* returnSize){
    int *result = (int *)malloc(sizeof(int) * ASize);
    *returnSize = 0;
    qsort(A, ASize, sizeof(int), compare);
    int i;
    int j;
    int idx = 0;

    for (i = 0 ; i < ASize; i++) {
        for (j = 0 ; j < ASize; j++) {
            if (B[i] < A[j]) {
                result[idx++] = A[j];
                A[j] = USEDMAX;
                break;
            }
        }
        if (j == ASize) {
            for (j = 0; j < ASize; j++) {
                if (A[j] != USEDMAX) {
                    result[idx++] = A[j];
                    A[j] = USEDMAX;
                    break;
                }
                
            }
        }
    }

    *returnSize = idx;
    return result;
}
```
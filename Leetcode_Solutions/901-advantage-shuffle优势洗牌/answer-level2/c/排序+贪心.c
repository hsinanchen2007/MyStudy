### 解题思路
把A排序，和B对比，不明白为啥少了一次排序时间更久了。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int Compare (const void *a, const void *b)
 {
     return *(int*)a - *(int*)b;
 }
int* advantageCount(int* A, int ASize, int* B, int BSize, int* returnSize){
    int maxValue = 1000000000;
    int* retArr = NULL;
    int count = 0;
    int find = 0;
    int minA = 0;
    *returnSize = ASize;
    if (ASize == 1) {
        return A;
    }

    qsort(A, ASize, sizeof(int), Compare);
    retArr = (int*)malloc(ASize * sizeof(int));
    memset(retArr, 0, ASize * sizeof(int));

    for (int i = 0; i < BSize; i++) {
        find = 0;
        minA = -1;
        for (int j = 0; j < ASize; j++) {
            // 提前记录A中最小的值，后面就不用循环查找了
            if (A[j] < maxValue && minA < 0) {
                minA = j;
            }
            if(A[j] > B[i] && A[j] < maxValue) {
                retArr[count] = A[j];
                A[j] = maxValue+1;
                count++;
                find = 1;
                break;
            }

        }
        if(!find) {
            // 没有找到合适的就把最小的给他           
            //for(int k = 0; k < ASize; k++) {
                //if(A[k] < maxValue) {
                    retArr[count] = A[minA];                              
                    A[minA] = maxValue+1;
                    //break;
               //}
            //}
            count++;
        }
        //qsort(A, ASize, sizeof(int), Compare);
    }
    return retArr;
}
```
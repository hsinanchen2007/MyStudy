### 解题思路
求出可能的最大长度，在该长度下如果存在则输出，不存在即跳过

### 代码

```c
#include <math.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int max = (int) sqrt(2 * target);
    int n = max;
    int ** results = (int**) malloc(max * sizeof(int *));
    int ** resultHead = results;
    int * returnColumnSizesResult = (int*) malloc(max * sizeof(int));
    *returnColumnSizes = returnColumnSizesResult;
    *returnSize = 0;
    while (n > 1){
        bool isOk = false;
        int start = 0;
        if (n % 2 == 0 && target % n == n / 2){
            start = target/n - n/2 + 1;
            isOk = true;
        }else if(n % 2 == 1 && target % n == 0){
            start = target/n - n/2;
            isOk = true;
        }
        if (isOk){
            int* result = (int*)malloc(n * sizeof(int));
            for (int i = 0; i < n; i ++){
                *(result + i) = i + start;
            }
            *results = result;
            results++;
            *returnColumnSizesResult = n;
            returnColumnSizesResult++;
            (*returnSize)++;
        }
        n--;
    }
    return resultHead;
}
```
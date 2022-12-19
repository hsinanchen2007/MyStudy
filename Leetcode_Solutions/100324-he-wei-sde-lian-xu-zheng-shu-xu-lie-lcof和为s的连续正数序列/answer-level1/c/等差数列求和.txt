### 解题思路
1. (i+n)*(n-i+1)/2=target，算出n
2. i从1循环到target/2
3. 每个n的解按等差数列求和后为target，则输出。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int i;
    int j;
    int idx = 0;
    int curSize = 1000;
    int ** result = (int**)malloc(sizeof(int*) * curSize);
    int * resultCol = (int**)malloc(sizeof(int) * curSize);

    for (i=1; i<=target/2; i++) {
        int tmp = (sqrt(1+4*((long long)i*i-i+2*target)) - 1)/2;
        if ((i+tmp)*(tmp-i+1)/2 != target) continue;
        //printf(" %d %d\n", i, tmp);

        int *solution = (int*)malloc(sizeof(int) * (tmp-i+1));
        for (j=0; j<tmp-i+1; j++) solution[j] = i+j;
        result[idx] = solution;
        resultCol[idx++] = (tmp-i+1);
    }

    *returnSize = idx;
    *returnColumnSizes = resultCol;
    return result;
}
```
### 解题思路


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){

    *returnSize = rowIndex + 1;
    int* ret = (int*)malloc(sizeof(int)*(rowIndex + 1));
    for(int i=0;i<rowIndex+1;++i)
        ret[i]=0;

    //关键步骤
    ret[0] = 1;
    for (int i = 0; i <= rowIndex; i++) {
        for (int j = i; j > 0; j--) {
            ret[j] = ret[j] + ret[j - 1];
        }
    }

    return ret;
}
```
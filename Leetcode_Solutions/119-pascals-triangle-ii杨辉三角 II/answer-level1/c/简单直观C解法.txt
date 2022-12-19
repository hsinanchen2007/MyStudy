为了只使用k大小空间同时数据不被破坏，只能从右向左计算。有点像dp方程：
外循环：i = 0 to k
内循环：j = i to 0
计算：v[j] = v[j] + v[j-1]
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1

```
int* getRow(int rowIndex, int* returnSize){
    int* ret = calloc(rowIndex + 1, sizeof(int));
    ret[0] = 1;
    for (int i = 0; i <= rowIndex; i++) {
        for (int j = i; j > 0; j--) {
            ret[j] = ret[j] + ret[j - 1];
        }
    }
    
    *returnSize = rowIndex + 1;
    return ret;
}
```

![image.png](https://pic.leetcode-cn.com/b3241f1b8e3a97ea4c728d480797a2716142dbd406bf86da8b79110c317cfc0a-image.png)


杨辉三角每一行可通过前一行推算，具有对称性，且每一行比前一行多一个元素。
可利用该特点先申请目标行大小的数组，然后计算每行结果时从数组的最后开始倒序存放。
如下图所示，第i行（从0开始）的开始位置j=(rowIndex - i)置1，从该位置开始每递增1，都有：
    rowNums[j] = rowNums[j] + rowNums[j + 1];
以求第3行为例：
rowNums[0] = 1, rowNums[1] = rowNums[1] + rowNums[2] = 1 + 2 = 3, ......
0行： _ _ _ 1
1行： _ _ 1 1
2行： _ 1 2 1
3行： _ _ _ _


```
int* getRow(int rowIndex, int* returnSize){
    int i, j;
    int numsSize = rowIndex + 1;
    int rowSize = 0;
    int rowStartIdx = 0;
    int* rowNums = NULL;

    if (rowIndex< 0 || returnSize == NULL) {
        *returnSize = 0;
        return NULL;
    }

    rowNums = (int*)calloc(numsSize, sizeof(int));
    rowNums[rowIndex] = 1;

    for (i = 0; i <= rowIndex; i++) {
        rowSize = i + 1;
        rowStartIdx = rowIndex - i;
        rowNums[rowStartIdx] = 1;
        for (j = rowStartIdx + 1; j < rowIndex; j++) {
            rowNums[j] = rowNums[j] + rowNums[j + 1];
        }
    }

    *returnSize = numsSize;

    return rowNums;
}
```




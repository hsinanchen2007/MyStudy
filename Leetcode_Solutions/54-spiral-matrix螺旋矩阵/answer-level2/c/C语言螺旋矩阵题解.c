看到C语言选手很少而且数组题用C写坑多，方法用的是高赞的上下左右边界方法，然后总结一下用C语言会碰到的坑。

坑主要是在为空矩阵的情况：

- 不大明白为什么`matrixColSize`是一个指针变量？想用`m, n`来简化一下结果之前空指针不能给`n`赋值 
- 空矩阵时直接返回`NULL`就可以，但是注意`returnSize`的值要改成0（可能是C语言中假装用于调用测试的主函数内，要靠`returnSize`遍历输出

```c
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int m = matrixSize, n, *res;
    if (!m || !matrixColSize) {
        *returnSize = 0;
        return NULL;
    }
    else {
        n = *matrixColSize; 
        *returnSize = m * n;
        res = (int*)malloc(*returnSize * sizeof(int));
    }
    int up = 0, down = m - 1, l = 0, r = n - 1, i, cnt = 0;
    /* 设置螺旋的四个边界，一条边遍历完成后，边界往“内”移，边界重合后出现交叉后结束 */
    while (1) {
        for (i = l; i <= r; i++) res[cnt++] = matrix[up][i];
        if (++up > down) break;
        for (i = up; i <= down; i++) res[cnt++] = matrix[i][r];
        if (--r < l) break;
        for (i = r; i >= l; i--) res[cnt++] = matrix[down][i];
        if (--down < up) break;
        for (i = down; i >= up; i--) res[cnt++] = matrix[i][l];
        if (++l > r) break;
    }
    return res;
}
```


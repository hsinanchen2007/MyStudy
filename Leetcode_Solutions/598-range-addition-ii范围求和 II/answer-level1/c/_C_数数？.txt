### 解题思路
这题的目标是算最大值的个数，所以我们没必要一定要把矩阵每个值按规则加1直到结束，那实在是太麻烦了；
我们只要找到操作数中的最小行，最小列就可以了，意味着最小行与最小列区间的值被累加的次数最多；
如给定m=3,n=3; 
ops=[[2,2],[1,2],[1,1]]
意味着对于[2,2]区间，我们累加第0行的第0列到第1列，累加第1行的第0列到第1列，共4个元素加过了1
[1,2]，累加第0行的第0列到第1列，共2个元素
[1,1]，累加第0行的第0列到第0列，共1个元素
综上对于array[0][0]这个元素累加了3次，为最大值，个数为1个（为array[0][0]，也就是1*1）。
哦，这里使用了qsort对二维指针排序（着重练手二维指针排序，也可以使用各种shell排序、大根堆排序、归并排序等）
![123.PNG](https://pic.leetcode-cn.com/7e28ac35631230b7e6ebc6db5b8756758cd0c7a1570275dbba9e93f8284b6ccd-123.PNG)


### 代码

```c
int cmpfir(const void **ele1, const void **ele2)
{
    int **p1 = (int **)ele1;
    int **p2 = (int **)ele2;
    if (p1[0][0] < p2[0][0]) {
        return -1;
    } else if (p1[0][0] == p2[0][0]) {
        return 0;
    } else {
        return 1;
    }
}
int cmpsec(const void **ele1, const void **ele2)
{
    int **p1 = (int **)ele1;
    int **p2 = (int **)ele2;
    if (p1[0][1] < p2[0][1]) {
        return -1;
    } else if (p1[0][1] == p2[0][1]) {
        return 0;
    } else {
        return 1;
    }
}
int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize) {
    int minRow, minCol;
    if (ops == NULL || opsSize == 0 || *opsColSize == 0) {
        return m * n;
    }
    
    qsort(ops, opsSize, sizeof(int) * 2, cmpfir);
    minRow = ops[0][0];
    qsort(ops, opsSize, sizeof(int) * 2, cmpsec);
    minCol = ops[0][1];
    return minRow * minCol;
}
```
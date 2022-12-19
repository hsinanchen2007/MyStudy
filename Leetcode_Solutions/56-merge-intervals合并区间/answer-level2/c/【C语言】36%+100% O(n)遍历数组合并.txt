### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/cd442f599e609064a11e3791e610f72d9145c3f09e64a29e548115edca43245d-image.png)

1.思路：
（1）首先对输入的二维数组intervals按第一列的大小做排序，通过排序，能够简化后续的算法实现难度。
（2）假设经过合并后的区间存储在retarray中，那么，retarray的第一行存储intervals的第一行。
（3）开始按行遍历二维数组intervals：
     a.当retarray当前行中的左区间节点小于intervals当前行的左区间节点，并且retarray当前行中的右区间节点也大于intervals当前行的右区间节点，说明intervals当前行所定义的区间是retarray当前行所定义区间的子集，可以忽略intervals当前行直接覆盖，跳过去，继续遍历intervals下一行。
     b.继续比较各种情形的区间范围。
     .......
2.corner condition：
（1）.[]空区间；
（2）.定义的各区间没有按有小到大的顺序排列；
（3）.各个区间定义的交叉形式；
3.知识点总结：
（1）二维数组的分配方法：
    int ** retarray = NULL;
    retarray = (int **)malloc(intervalsSize * sizeof(int *));
    for(i = 0; i < intervalsSize; i++) {
        retarray[i] = (int *)malloc(2 * sizeof(int));
        memset(retarray[i], 0x00, 2 * sizeof(int));
    }
（2）leetcode返回值的赋值方法：
    *returnSize = j;
    int *temp = (int *)malloc(j * sizeof(int));
    for(i = 0; i < j; i++) {
        temp[i] = 2;
    }
    *returnColumnSizes = temp;

（3）用qsort对二维数组进行排序：
int cmpf(const void *a,const void *b)
{
    int *ap = *(int **)a;
    int *bp = *(int **)b;
    return ap[0] > bp[0];
}
4.耗时：long~~，。主要耗时点：
（1）算法设计；
（2）leetcode返回值用法不熟悉；
（3）cmpf的实现不熟悉；


### 代码

```c
/* *
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmpf(const void *a, const void *b)
{
    int *ap = *(int **)a;
    int *bp = *(int **)b;
    return ap[0] > bp[0];
}
int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes)
{
    int i = 0;
    int j = 0;
    int **retarray = NULL;
    if (intervalsSize == 0) {
        *returnSize = 0;
        return;
    }
    qsort(intervals, intervalsSize, 2 * sizeof(int), cmpf);
    retarray = (int **)malloc(intervalsSize * sizeof(int *));
    for (i = 0; i < intervalsSize; i++) {
        retarray[i] = (int *)malloc(2 * sizeof(int));
        memset(retarray[i], 0x00, 2 * sizeof(int));
    }
    retarray[0][0] = intervals[0][0];
    retarray[0][1] = intervals[0][1];
    for (i = 1, j = 0; i < intervalsSize; i++) {
        if (retarray[j][0] < intervals[i][0] && retarray[j][1] > intervals[i][1]) {
            continue;
        } else if (retarray[j][0] > intervals[i][0] && retarray[j][1] < intervals[i][1]) {
            retarray[j][0] = intervals[i][0];
            retarray[j][1] = intervals[i][1];
        } else if (retarray[j][0] > intervals[i][0] && retarray[j][1] > intervals[i][1]) {
            if (retarray[j][0] <= intervals[i][1]) {
                retarray[j][0] = intervals[i][0];
            } else {
                printf("shouldn't be exist\n");
            }
        } else if (retarray[j][0] <= intervals[i][0] && retarray[j][1] < intervals[i][1]) {
            if (intervals[i][0] <= retarray[j][1]) {
                retarray[j][1] = intervals[i][1];
            } else {
                j++;
                retarray[j][0] = intervals[i][0];
                retarray[j][1] = intervals[i][1];
            }
        }
    }
    j++;
    *returnSize = j;
    int *temp = (int *)malloc(j * sizeof(int));
    for (i = 0; i < j; i++) {
        temp[i] = 2;
    }
    *returnColumnSizes = temp;
    return retarray;
}
```
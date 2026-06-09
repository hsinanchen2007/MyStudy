解题思路 这题最简单的做法就是去找所给二维矩阵的第一列了和第二列最小的数，因为数组每行的两个数都可以划分一个矩形，最后和最大的数，必定是共同的重叠部分，所以只需找数组每列的最小值，乘积为所求。
```
int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize){
    int i, j;
    int min_c = m, min_r = n;
    for(i = 0;i < opsSize;i++)
    {
        if(ops[i][0] < min_c)
        {
            min_c = ops[i][0];
        }
        if(ops[i][1] < min_r)
        {
            min_r = ops[i][1];
        }
    }
    return min_c * min_r;

}
```

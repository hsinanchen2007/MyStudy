### 解题思路
（本题练习指针和数组）
1)当前行的最左边和最后边的元素为1；
2)中间的元素可以由上一行元素递推得到：a[i][j] = a[i-1][j-1] + a[i-1][j]; 
![image.png](https://pic.leetcode-cn.com/44ff0aea9e84763fb57e49061c4e6b6ef3e8d1a785d0e18f055acace542de933-image.png)

### 代码

```c
int Yanghui(int n, int *** rowList){
    int i, j;
    int **a;
    
    a = *rowList;
    i = n-1;
    j = 0;

    a[i] = (int *)malloc(n * sizeof(int));

    if (n == 1) {
        a[0][0] = 1;
        return 1;
    } else if (n == 2) {
        a[1][0] = 1;
        a[1][1] = 1;
        return 2;
    }        

    a[i][j++] = 1;
    for (; j <= n - 2; j++ ) {
        a[i][j] = a[n-2][j-1] + a[n-2][j]; 
    }
    a[i][j] = 1;

    return n; 
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **rowList;
    int rowNb;
    int *pCol;

    int n;

    // 行指针个数
    rowNb   = numRows;

    rowList = (int **)malloc(rowNb * sizeof(int *));
    *returnSize = rowNb;

    // 申请空间存储每行元素个数
    pCol    = (int *)malloc(rowNb * sizeof(int));

    // 计算每行的元素
    for (n = 0; n < rowNb; n++) {
        pCol[n] = Yanghui(n+1, &rowList);
    }

    (*returnColumnSizes) = pCol;

    return rowList;
}


```
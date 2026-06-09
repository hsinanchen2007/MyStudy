### 解题思路
初始条件,第一横行和第一纵列都是1
状态转移方程：到达第n行m列的路径数目等于到达第n-1行m列的路径数加上到达第n行m-1列的路径数（因为从这两个点再走一步就可以到达finish）

动态规划就是把大问题化成小问题，在解决小问题的过程中，记录小问题的结果，维护起来，在解决比这些小问题要大一点的大问题时，使用比它小一点问题的结果...
感觉跟递归的差异就是把小问题的结果记录了下来。因此转移方程跟递归一样，初始条件跟递归也一样，节省时间就在记录了中间过程。

![截图.PNG](https://pic.leetcode-cn.com/3f4b12593e18ee2458d65c70ed94c46b6c9c963313e01d2e900ea85abd14e7ee-%E6%88%AA%E5%9B%BE.PNG)


### 代码

```c
int uniquePaths(int m, int n){
    int maxPaths = 0;
    //特殊情况
    if ((m == 0) || (n == 0)) {
        return 0;
    }

    //申请一个二维数组用来存在动态规划过程中产生的数据
    int** array = (int **)malloc(sizeof(int *) * n);
    memset(array, 0, sizeof(int *) * n);
    for (int k = 0; k < n; k++) {
        *(array + k) = (int *)malloc(sizeof(int) * m);
        memset(*(array + k), 0, sizeof(int) * m);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //初始条件,第一横行和第一纵列都是1
            if ((i == 0) || (j == 0)) {
                *(*(array + i) + j) = 1;
            } else {
                //状态转移方程：到达第n行m列的路径数目等于到达第n-1行m列的路径数加上到达第n行m-1列的路径数（因为从这两个点再走一步就可以到达finish）
                *(*(array + i) + j) = *(*(array + i - 1) + j) + *(*(array + i) + j - 1);
            }    
        }
    }
    maxPaths = *(*(array + n - 1) + m - 1);

    for (int k = 0; k < n; k++) {
        free(*(array + k));
    }
    free(array);
    return maxPaths;

}
```
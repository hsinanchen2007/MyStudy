### 解题思路
![演示文稿1.jpg](https://pic.leetcode-cn.com/c30f5998bb89ac04dc00aa84b61b73f0806f51f328497c1ffd50f2822332a2d0-%E6%BC%94%E7%A4%BA%E6%96%87%E7%A8%BF1.jpg)

- 上图中从坐标(0,0)到(1,1)有2种路径，从(0,0)到(2,3)有10种路径
- dp[m][n] = dp[m-1][n] + dp[m][n-1]

### 代码

```c
int uniquePaths(int m, int n){

    int **arr = (int **)malloc(sizeof(int*) *n);
    int i,v;
    for(i=0;i<n;i++){
        arr[i] = (int *)malloc(sizeof(int) *m);
        for(v=0;v<m;v++)
            if(i==0||v==0) arr[i][v] = 1;
            else arr[i][v] = arr[i-1][v] + arr[i][v-1];
    }
    return arr[n-1][m-1];
}
```
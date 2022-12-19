### 解题思路
此处撰写解题思路

### 代码
方法一：暴力递归 ，最容易想出来的方法了，直接超时
```
void recursion(int m,int n,int i,int j,int* result){
    if(i<m){
        recursion(m,n,i+1,j,result);
    }
    if(j<n){
        recursion(m,n,i,j+1,result);
    }
    if(i==m && j==n){
        (*result)++;
    }
}

int uniquePaths(int m, int n){
    int result;
    recursion(m,n,1,1,&result);
    return result;
}
```


方法二：动态规划，用dp[m][n]来表示m×n网格有多少路径，其中下/右边界上dp[1][n]=dp[m][1]=1,我们得到公式dp[m][n] = dp[m-1][n] + dp[m][n-1];
      时间复杂度O(m*n),空间复杂度O(m*n),其实空间负责度可以优化为O(min(m,n))
```c
int uniquePaths(int m, int n){
    int dp[m+1][n+1];
    for(int i=1;i<=m;i++){
        dp[i][1] = 1;
    }
    for(int j=1;j<=n;j++){
        dp[1][j] = 1;
    }
    for(int i=2;i<=m;i++){
        for(int j=2;j<=n;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m][n];
}
```
```
动态规划，优化了空间复杂度O(min(m,n))
int uniquePaths(int m, int n){
    int min = (m<n?m:n);
    int max = (m>n?m:n);
    int dp[min];
    for(int i=0;i<min;i++){
        dp[i] = 1;                    //dp[0]表示下/右边界上格子路线的始终等于1
    }
    for(int i=0;i<max-1;i++){
        for(int j=1;j<min;j++){
            dp[j] = dp[j-1]+dp[j];
        }
    }
    return dp[min-1];
}
```


方法三：本以为动态规划已经挺好的了，结果在评论区看到一个公式就解决了.....人傻了，这确实是个高中都会的排列组合啊....
     机器人一定会走m+n-2步，即从m+n-2中挑出m-1步向下走，或者选n-1步往右走,即C(m+n-2，min(m-1,n-1)); 
```
int uniquePaths(int m, int n){
    long result = 1;
    int min = (m<n?m:n);
    int N=m+n-2,k=min-1;      //c(N,k)
    for(int i=0;i<min-1;i++){
        result *= N--;
    }
    for(int i=0;i<min-1;i++){
        result /= k--;
    }
    (int)result;
    return result;
}
```

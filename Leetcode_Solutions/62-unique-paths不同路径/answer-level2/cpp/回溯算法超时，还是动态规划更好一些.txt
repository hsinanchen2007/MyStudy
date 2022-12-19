### 解题思路
开始采用了回溯算法发现超时，参考了评论区又采用了动态规划，其实大多数情况能用动态规划的都是比较优的算法，多理解多用吧。评论区还有根据方程解出来的，这道题看做一道数学题貌似更简便一些。
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.2 MB, 在所有 C++ 提交中击败了65.97%的用户
### 代码

```cpp
class Solution{
public:
    int uniquePaths(int m,int n){
        int dp[m][n];
        memset(dp, 0, m*n);
        for(int i=0;i<m;i++){
            dp[i][0] = 1;
        }
        for(int j=0;j<n;j++){
            dp[0][j] = 1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
```
回溯算法

```cpp
class Solution{
public:
    int uniquePaths(int m,int n){
        int i = 1;
        int j = 1;
        int res = 0;
        res = con(m, n, i, j, res);
        return res;
    }
    int con(int m,int n,int i,int j,int res){
        if(i==m&&j==n){
            res++;
            return res;
        }
        if(i+1<=m){
            res = con(m,n,i+1,j,res);
        }
        if(j+1<=n){
            res =  con(m,n,i,j+1,res);
        }
        return res;

    }
};

```
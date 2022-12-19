方法一 递归 超时
递归方法，采用自顶向下的思想，拆分为若干子问题，但是造成了子问题的重复求解。
```
class Solution {
public: 
    int uniquePaths(int m, int n) { 
        return helper(m,n);
    }
    int helper(int m,int n){
        if(m <= 0 || n <= 0) return 0;
        if(m == 1 || n == 1) return 1; //只能一直向右走或向下走，所以路径数为 1
        return helper(m-1,n)+helper(m,n-1);
    }
};
```
```
class Solution {
public: 
    int uniquePaths(int m, int n){
        if(m <= 0 || n <= 0) return 0;
        if(m == 1 || n == 1) return 1; //只能一直向右走或向下走，所以路径数为 1
        return uniquePaths(m-1,n) + uniquePaths(m,n-1);
    }
};
```
方法二 备忘录递归 自顶向下
递归过程中有很多是重复的，比如说向右走一步（m+1）再向下走一步（n+1）和向下走一步（n+1）再向右走一步（m+1）走到的位置是相同的，在两个过程中重复的去求了 f[m+1][n+1]的路径数。
利用“备忘录”记住曾经求得的路径数可以避免重复过程。
```
class Solution {
public: 
    vector<vector<int>> a;
    int uniquePaths(int m, int n){
        a=vector<vector<int>>(m,vector<int>(n,0));
        return helper(m-1,n-1);
    }
    int helper(int m, int n){
        if(m < 0 || n < 0) return 0;
        if(m == 0 || n == 0) return 1;
        if(a[m][n] > 0) return a[m][n];
        a[m][n] =helper(m-1,n) + helper(m,n-1);;
        return a[m][n];
    }
};
```
方法三 动态规划 自底向上
将原问题拆分为若干子问题，每个子问题只解一次，把解保存在一个表中，巧妙的避免了子问题的重复求解。
```
class Solution {
public: 
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};
```
```
class Solution {
public: 
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++)  dp[0][i] = 1;
        for (int i = 0; i < m; i++)  dp[i][0] = 1;
        for (int i = 1; i < m; i++) 
            for (int j = 1; j < n; j++) dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[m-1][n-1];
    }
};
```
空间压缩
```
class Solution {
public: 
    int uniquePaths(int m, int n) {
        int dp[n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) dp[j] = 1;
                else dp[j] = dp[j-1] + dp[j];
            }
        }
        return dp[n-1];
    }
};
```
```
class Solution {
public: 
    int uniquePaths(int m, int n) {
        int dp[n];
        for(int i= 0; i<n ;i++) dp[i]=1;
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)  dp[j] = dp[j] + dp[j-1];
        return dp[n-1];  
    }
};
```




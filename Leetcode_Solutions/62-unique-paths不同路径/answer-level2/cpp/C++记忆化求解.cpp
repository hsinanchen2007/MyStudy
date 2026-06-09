这题类似于求斐波那契数列的问题，有两种解法：
（1）用回溯，然而如果直接用递归，那么时间复杂度会很高，因为有很多相同的问题会被重复的计算。因此在求解的时候需要记忆子问题的结果，这里我用了一个二维的101维度的数组。
```
class Solution {
public:
    int path[101][101];
    Solution()
    {
        memset(path,-1,sizeof(path));
    }
    int uniquePaths(int m, int n) {
        if(path[m][n]!=-1)
            return path[m][n];
        if(m<0 || n<0)
            return 0;
        if(m==1 ||n==1)
            return 1;
        path[m-1][n]=uniquePaths(m-1,n);
        path[m][n-1]=uniquePaths(m,n-1);
        return (path[m-1][n]+path[m][n-1]);
    }
};
```
(2)用动态规划的思想，两层for循环遍历
```
class Solution {
public:
    int path[101][101];
    Solution()
    {
        memset(path,-1,sizeof(path));
    }
    int uniquePaths(int m, int n) {
        if(m==1 || n==1)
            return 1;
        for(int i=1;i<=m;i++)
            path[i][1]=1;
        for(int i=1;i<=n;i++)
            path[1][i]=1;
        for(int i=2;i<=m;i++)
            for(int j=2;j<=n;j++)
                path[i][j]=path[i-1][j]+path[i][j-1];
        return path[m][n];
    }
};
```


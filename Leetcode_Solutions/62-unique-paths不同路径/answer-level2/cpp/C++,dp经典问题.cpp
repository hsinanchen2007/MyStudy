```
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>mp(m+1,vector<int>(n+1,0));//全局初始化
        for(int i=0;i<m;i++)mp[i][0]=1;//第一列的走法初始为1，当做第一列的初始化
        for(int i=0;i<n;i++)mp[0][i]=1;//第一行初始化为1，
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                mp[i][j]=mp[i-1][j]+mp[i][j-1];//之后的结果是之前的结果向右或者向下得到的。。。
            }
        }
        return mp[m-1][n-1];
    }
};
```

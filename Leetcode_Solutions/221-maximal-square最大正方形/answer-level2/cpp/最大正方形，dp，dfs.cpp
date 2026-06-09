- 方法一
别想那么多，就是遍历，遍历就完事了。有一说一，我也不知道属不属于BFS,更像是暴力搜索，反正想法简单，本以为会超时，没想到还可以这么高，真是意料之外
```
//广度优先
class Solution {
public:
    void bfs(int& res,int row,int col,vector<vector<char>>& matrix){
        //扫描矩形，能进来这个函数说明正方形至少为1
        res=max(res,1);
        int count=1;
        while(row+count<matrix.size()&&col+count<matrix[0].size()){
            for(int i=row;i<=row+count;i++){
                for(int j=col;j<=col+count;j++){
                    if(matrix[i][j]=='1')continue;
                    else return;
                }
            }
            //结束一轮之后更新最大值
            res=max(res,(count+1)*(count+1));
            count++;
        } 
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size();
        if(!row)return 0;//输入为Kong特判
        int col=matrix[0].size();
        int res=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='1'){
                    bfs(res,i,j,matrix);
                }else{
                    continue;
                }
            }
        }
        return res;
    }
};
```
- 方法二
```
//动态规划
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size();
        if(!row)return 0;
        int col=matrix[0].size();
        vector<vector<int>>dp(row+1,vector<int>(col+1,0));
        int res=0;
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                    res=max(dp[i][j]*dp[i][j],res);
                }
            }
        }
        return res;
    }
};
```

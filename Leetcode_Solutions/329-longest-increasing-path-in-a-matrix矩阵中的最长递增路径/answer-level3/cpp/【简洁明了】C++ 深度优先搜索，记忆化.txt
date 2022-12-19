```
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        int res=0;
        vector<vector<int>>visited(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                res=max(res,dfs(matrix,i,j,visited));
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>&matrix,int i,int j,vector<vector<int>>&visited){
        if(visited[i][j]!=0){
            return visited[i][j];
        }
        int M=matrix.size(), N=matrix[0].size();
        int l=1,r=1,u=1,d=1;
        if(i-1>=0&&matrix[i-1][j]>matrix[i][j]) u=1+dfs(matrix,i-1,j,visited);
        if(j-1>=0&&matrix[i][j-1]>matrix[i][j]) l=1+dfs(matrix,i,j-1,visited);
        if(i+1< M&&matrix[i+1][j]>matrix[i][j]) d=1+dfs(matrix,i+1,j,visited);
        if(j+1< N&&matrix[i][j+1]>matrix[i][j]) r=1+dfs(matrix,i,j+1,visited);
        visited[i][j]=max(max(l,r),max(u,d));
        return visited[i][j];
    }
};
```
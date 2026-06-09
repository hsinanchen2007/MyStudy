首先可以推断出本题存在最优子结构 凡是存在最优子结构 必然存在重叠子问题 故直接用回溯法的dfs（一条条路径比较不断更新最大值）必然会存在大量重复计算 为解决这种问题 应采取记忆化搜索的手段 用最优子结构形式进行深度优先搜索 即所求最大值来源于子问题中的最大值再+1（而不是采取回溯法的dfs形式 注意区别） 并记录所经过的所有子问题 等到下一次碰到该子问题时 应直接return即可

```
int max(int a,int b)
{if(a>b) return a;
return b;}
int ans;
void dfs(int ** matrix,int row,int col,int x,int y,int dp[][col]){
if(dp[x][y])  return;
if(x>0) {if(matrix[x][y]>matrix[x-1][y]) {dfs(matrix,row,col,x-1,y,dp);}}
if(y>0) {if(matrix[x][y]>matrix[x][y-1]) {dfs(matrix,row,col,x,y-1,dp);} }
if(x<row-1) {if(matrix[x][y]>matrix[x+1][y]) {dfs(matrix,row,col,x+1,y,dp);}}
if(y<col-1) {if(matrix[x][y]>matrix[x][y+1]) {dfs(matrix,row,col,x,y+1,dp);}}
if(x>0&&matrix[x][y]>matrix[x-1][y]) dp[x][y]=max(dp[x][y],dp[x-1][y]);
if(y>0&&matrix[x][y]>matrix[x][y-1]) dp[x][y]=max(dp[x][y],dp[x][y-1]);
if(x<row-1&&matrix[x][y]>matrix[x+1][y]) dp[x][y]=max(dp[x][y],dp[x+1][y]);
if(y<col-1&&matrix[x][y]>matrix[x][y+1]) dp[x][y]=max(dp[x][y],dp[x][y+1]);
dp[x][y]++;
}


int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize){
int row=matrixSize;
int col=*matrixColSize;
if(row==0) return 0;
int dp[row][col];
int i,j;
int MAX=0;
memset(dp,0,sizeof(dp));
for(i=0;i<row;i++)
for(j=0;j<col;j++)
{dfs(matrix,row,col,i,j,dp);
MAX=max(MAX,dp[i][j]);
}
return MAX;
}
```
运行结果:
![捕获 - 副本.PNG](https://pic.leetcode-cn.com/3df5bc103e048e493ead91280c804c38b70ba367e5c22b08e741be8ec1099789-%E6%8D%95%E8%8E%B7%20-%20%E5%89%AF%E6%9C%AC.PNG)





时间复杂度:o(m*n)
空间复杂度:o(m*n)


### 解题思路
怎样求一个邻接矩阵里的连通分量，就像蓝桥杯的草坪题目（只是那个用bfs)一样。

### 代码

```cpp
class Solution {
public:   //岛屿的数量这题就像二维数组求最大的连通分量。。。
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) {
                    res=max(res,DFS(grid,i,j));
                }
            }
        }
        return res;
    }
    
    int DFS(vector<vector<int>>&grid,int i,int j){
//官方在这里添加了终止条件cur_i < 0 or cur_j < 0 or cur_i == len(grid) or cur_j == len(grid[0]) or grid[cur_i][cur_j] != 1 所以我们下面就不需要这么多的判断条件。。很牛皮
        int ans=1;  //注意：初始化要为1（符合就加一）
        grid[i][j]=0;
        if(i-1>=0&&grid[i-1][j]==1) ans+=DFS(grid,i-1,j);
        if(i+1<grid.size()&&grid[i+1][j]) ans+=DFS(grid,i+1,j);
        if(j-1>=0&&grid[i][j-1]==1) ans+=DFS(grid,i,j-1);
        if(j+1<grid[0].size()&&grid[i][j+1]==1) ans+=DFS(grid,i,j+1); //注意j在纵坐标：j+1<grid[0].size()
        return ans;
    }
};
```
### 解题思路
1. 特别判断：如果起点或终点为1，则返回-1
2. 设置起点`grid[0][0]`为1，将其添加到queue作为首元素
3. 从队列首元素开始bfs扩展节点，grid[i][j]为0代表没有访问过，否则该节点在之前已经访问（被扩展）过，直到访问到`grid[n-1][n-1]`返回结果，否则返回-1

### 代码

```cpp
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] ==1) return -1;
        queue<pair<int,int>> q;
        grid[0][0] = 1;
        q.push({0,0});
        while(!q.empty()){
            auto p = q.front(); q.pop();
            int dx = p.first;
            int dy = p.second;
            if(dx == n-1 && dy == n-1)return grid[dx][dy];
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int current_x = dx+i;
                    int current_y = dy+j;
                    //判断坐标是否合法（越界）
                    if(current_x<0 || current_x>=n || current_y<0 || current_y>=n || grid[current_x][current_y]!=0) continue;
                    grid[current_x][current_y] = grid[dx][dy]+1;
                    q.push({current_x, current_y});
                }
            }
        } 
        return -1;
    }
};

```
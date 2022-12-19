### 解题思路
- 直观的深度优先搜索方法，模拟遍历操作，复杂度较高；
- 更好的方法可以先遍历二维数组，找到总的岛屿个数，乘以四作为初始周长，如果一个岛屿方块的一侧有岛屿，则周长减一，最终得到整个面积。

### 代码

```cpp
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0, row = grid.size(), col = grid[0].size();
        stack<pair<int, int>> island;
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    island.push({i, j});  
                    break;
                }
            }
            if(island.size() == 1) break;
        }

        while(!island.empty()){
            int index_x = island.top().first;
            int index_y = island.top().second;
            island.pop();
            if(grid[index_x][index_y] == 1){
                grid[index_x][index_y] = -1;
                for(auto di:dir){
                    int x = index_x+di.first;
                    int y = index_y+di.second;
                    if(x>=0 && x<row && y>=0 && y<col){
                        if(grid[x][y] == 1) island.push({x, y});
                        else if(grid[x][y] == 0) res++;
                    }
                    else{
                        if((x<0) || (x>=row)) res++;
                        if((y<0) || (y>=col)) res++;
                    }
                }
            }
        }
        return res;
    }
};
```
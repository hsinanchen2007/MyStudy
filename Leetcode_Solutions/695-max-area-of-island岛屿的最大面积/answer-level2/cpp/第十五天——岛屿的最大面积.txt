### 解题思路

将遍历过的岛屿置为-1，使用栈保存尚未搜索的岛屿(BFS)。

### 代码

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int MaxArea = 0;  //最大面积
        int area = 0;   //岛屿面积
        pair<int, int> pos;  //当前位置
        pair<int, int> curr;    //当前位置的四领域坐标
        stack<pair<int, int>> island;  //使用栈存放未搜寻的岛
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  //四个方向：上下左右

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(1 == grid[i][j]){
                    grid[i][j] = -1;
                    island.push({i, j});
                    area = 1;
                    while(!island.empty()){
                        pos = island.top();
                        island.pop();
                        for(int k = 0; k < 4; k++){
                            curr.first = pos.first+dir[k].first;
                            curr.second = pos.second+dir[k].second;
                            if(curr.first >= 0 && curr.first < grid.size() && curr.second >= 0 && curr.second < grid[0].size()){
                                if(1 == grid[curr.first][curr.second]){
                                    area++;
                                    grid[curr.first][curr.second] = -1;
                                    island.push(curr);
                                }
                            }
                        }
                    }
                    MaxArea = max(MaxArea, area);
                }
            }
        }
        return MaxArea;
    }
};
```




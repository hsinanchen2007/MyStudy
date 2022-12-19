### 解题思路
最常见的矩阵的dfs类型，从每个room[x][y]==0,开始向四个方向搜索，只搜索room值大于room[x][y]+1的方向。

### 代码

```cpp
class Solution {
public:
    int index[4][2] = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (!rooms.size() || !rooms[0].size()) return;
        for (int i = 0; i < rooms.size(); ++i) {
            for (int j = 0; j < rooms[0].size(); ++j) {
                if (rooms[i][j]) continue;
                dfs(rooms, i, j, rooms[i][j]);
            }
        }
    }

    void dfs(vector<vector<int>>& rooms, int x, int y, int val) {
        rooms[x][y] = val;
        for (int i = 0; i < 4; ++i) {
            int cx = x + index[i][0];
            int cy = y + index[i][1];
            if (cx>=0&&cx<rooms.size()&&cy>=0&&cy<rooms[0].size()&&rooms[x][y]+1<rooms[cx][cy]) {
                dfs(rooms, cx, cy, rooms[x][y]+1);
            }
        }
    }
};
```
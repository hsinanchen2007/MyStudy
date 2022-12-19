### 解题思路
多源BFS（以前打比赛的时候硬是没用到过太菜了看了大佬的学到了）

### 代码

```cpp
class Solution {//BFS到每一个点的最短距离   多源BFS因为每个点到某点的距离先到了就是最短的距离
public:
    int maxDistance(vector<vector<int>>& grid) {
        int dire[4][2] = { 1,0,-1,0,0,1,0,-1 };
        int row = grid.size(), col = grid[0].size();
        queue<pair<int, int>>qu;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    pair<int, int>t(i, j);   //把所有陆地加入队列
                    qu.push(t);   //加入之后就是多源
                }
            }
        }
        //如果我们的地图上只有陆地或者海洋，请返回 -1。
        if (qu.size() == row * col || qu.size() == 0) return -1;

        int x, y,newx, newy;
        while (!qu.empty()) {
            x = qu.front().first;
            y = qu.front().second;
            qu.pop();
            for (int i = 0; i < 4; i++) {
                newx = x + dire[i][0];
                newy = y + dire[i][1];
                if (newx >= row || newx < 0 || newy >= col || newy < 0 || grid[newx][newy]>0) continue; //因为要么是陆地要没事海洋已经离其他陆地较近
                grid[newx][newy] = grid[x][y]+1;
                pair<int, int>t(newx, newy);
                qu.push(t);
            }
        }
        return  grid[x][y] - 1;
    }
};
```
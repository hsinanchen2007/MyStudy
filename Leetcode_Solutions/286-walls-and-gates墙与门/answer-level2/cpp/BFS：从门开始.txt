### 解题思路

暴力枚举每一个房间的位置复杂度很高，而从门开始BFS，只要O(N)时间就可以了。

**对于确定的起点和终点，BFS的两个方向是等价的。**

### 代码

```cpp
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if(m == 0)
            return;
        int n = rooms[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<pair<int, int>> Q;
        
        int i, j;
        for(i=0; i<m; i++)
            for(int j=0; j<n; j++) {
                if(rooms[i][j] == 0)
                    Q.emplace(i, j);
            }
        
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int level = 0;
        
        while(!Q.empty()) {
            auto pair = Q.front();
            Q.pop();
            int x = pair.first;
            int y = pair.second;
            // cout << x << "," << y << endl;
            
            for(int i=0; i<4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || rooms[nx][ny] < 0)
                    continue;
                if(rooms[nx][ny] == INT_MAX) {
                    rooms[nx][ny] = rooms[x][y] + 1;
                    // cout << "push: " << nx << "," << ny << endl;
                    Q.emplace(nx, ny);
                }
            }
        }
    }
};
```
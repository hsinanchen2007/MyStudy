### 解题思路
每一分钟遍历一层 同时对新鲜水果计数

### 代码

```cpp
class Solution {
public:
int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int, int>> q;
    int freshCount = 0; 
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j <grid[0].size(); j++) {
            if (grid[i][j] == 2) {
                q.push(make_pair(i,j));
            }
            if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    int min = 0;
    while (!q.empty() && freshCount > 0)
    {   
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = { 0, 0,-1, 1};
        int curSize = q.size();
        for (int i = 0; i < curSize; i++) {
            int srcX = q.front().first;
            int srcY = q.front().second;
            for(int j = 0; j < dx.size(); j++) {
                int dstX = srcX + dx[j];
                int dstY = srcY + dy[j];
                if (dstX >= 0 && dstX < grid.size() &&
                    dstY >= 0 && dstY < grid[0].size() && grid[dstX][dstY] == 1) {
                        freshCount--;
                        grid[dstX][dstY] = 2;
                        q.push(make_pair(dstX, dstY));
                    }
            }
            q.pop();

        }
        min++;
    }
    return freshCount ? -1 : min;
    
}
};
```
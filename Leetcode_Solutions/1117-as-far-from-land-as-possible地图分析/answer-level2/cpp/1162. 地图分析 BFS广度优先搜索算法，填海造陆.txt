用BFS算法，进行填海造陆，先找出所有的陆地，然后用BFS进行扩散，每扩散一层，计数器加1，然后进行填海造陆，直到所以的海洋变成陆地

```
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int direct[5] = { 0, 1, 0, -1, 0 };
        int gridSize = grid.size();
        int nx, ny;
        int ret = 0;
        int count;
        queue<pair<int, int>> queueList;
        int i, j;
        for (i = 0; i < gridSize; i++) {
            for (j = 0; j < gridSize; j++) {
                if (grid[i][j] == 1) {
                    queueList.push({i, j});
                }
            }
        }

        if (queueList.size() == 0 || queueList.size() == gridSize * gridSize) {
            return -1;
        }

        int queueSize;
        int loop;
        while (!queueList.empty()) {
            queueSize = queueList.size();
            count = 0;
            while (queueSize) {
                pair<int, int> frontVal = queueList.front();
                queueList.pop();
                for (loop = 0; loop < 4; loop++) { // 4个方向
                    nx = frontVal.first + direct[loop];
                    ny = frontVal.second + direct[loop + 1];
                    if (nx < 0 || ny < 0 || nx >= gridSize || ny >= gridSize || grid[nx][ny] == 1) {
                        continue;
                    }
                    count++;
                    grid[nx][ny] = 1;
                    queueList.push({nx, ny});
                }
                queueSize--;
            }

            if (count > 0) {
                ret++;
            }
        }

        return ret;
    }
};
```

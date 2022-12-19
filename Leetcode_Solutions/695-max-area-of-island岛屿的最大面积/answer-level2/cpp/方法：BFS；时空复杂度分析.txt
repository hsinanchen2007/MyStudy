### 解题思路
时间复杂度O(n^3)
空间复杂度O(n)

### 代码

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        if (!row) return 0;
        int col = grid[0].size();
        int maxArea = 0;
        queue<pair<int, int>> queue;
        set<pair<int, int>> used;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    //initialize
                    queue.push(pair(i, j));
                    used.insert(pair(i, j));
                    int count = 0;
                    // BFS
                    while (!queue.empty()) {
                        ++count;
                        auto cur = queue.front();
                        queue.pop();
                        int curRow = cur.first;
                        int curCol = cur.second;
                        // iterator
                        if (curRow > 0 && grid[curRow - 1][curCol] == 1 && used.find(pair(curRow - 1, curCol)) == used.end()) {
                            queue.push(pair(curRow - 1, curCol));
                            used.insert(pair(curRow - 1, curCol));
                        }
                        if (curRow < row - 1 && grid[curRow + 1][curCol] == 1 && used.find(pair(curRow + 1, curCol)) == used.end()) {
                            queue.push(pair(curRow + 1, curCol));
                            used.insert(pair(curRow + 1, curCol));
                        }
                        if (curCol > 0 && grid[curRow][curCol - 1] == 1 && used.find(pair(curRow, curCol - 1)) == used.end()) {
                            queue.push(pair(curRow, curCol - 1));
                            used.insert(pair(curRow, curCol - 1));
                        }
                        if (curCol < col - 1 && grid[curRow][curCol + 1] == 1 && used.find(pair(curRow, curCol + 1)) == used.end()) {
                            queue.push(pair(curRow, curCol + 1));
                            used.insert(pair(curRow, curCol + 1));
                        }
                    }
                    if (count > maxArea) maxArea = count;
                }
            }
        }
        return maxArea;
    }
};
```
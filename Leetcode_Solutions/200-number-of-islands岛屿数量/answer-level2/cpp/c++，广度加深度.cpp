广度内存消耗比深度大

```
class Solution {
    int maxRow = 0;
    int maxCol = 0;

private:
    int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool isValidPos(int row, int col) {
        return row >= 0 && row < maxRow && col >= 0 && col < maxCol;
    }

    void dfs(vector<vector<char>>& matrix, int row, int col) {
        cout << "cur point:" << row << "," << col << endl;

        if (matrix[row][col] == '1') {
            matrix[row][col] = '2';

            for (int dirt = 0; dirt < 4; ++dirt) {
                    int nextRow = row + direction[dirt][0];
                    int nextCol = col + direction[dirt][1];
                    cout << "next point:" << nextRow << "," << nextCol << endl;

                    if (isValidPos(nextRow, nextCol)) {
                        dfs(matrix, nextRow, nextCol);
                    }
            }
        }
    }

    void bfs(vector<vector<char>>& matrix, int row, int col) {
        queue<pair<int, int>> island;

        island.push(make_pair(row, col));
        matrix[row][col] = '2';

        while (island.empty() == false) {
            int curRow = island.front().first;
            int curCol = island.front().second;
            island.pop();

            for (int dirt = 0; dirt < 4; ++dirt) {
                int nextRow = curRow + direction[dirt][0];
                int nextCol = curCol + direction[dirt][1];

                if (isValidPos(nextRow, nextCol)) {
                    if (matrix[nextRow][nextCol] == '1') {
                        matrix[nextRow][nextCol] = '2';
                        island.push(make_pair(nextRow, nextCol));
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        this->maxRow = grid.size();
        if (maxRow == 0) {
            return result;
        }
        this->maxCol = grid[0].size();

        for (int row = 0; row < maxRow; ++row) {
            for (int col = 0; col < maxCol; ++col) {
                if (grid[row][col] == '1') {
                    result++;
                    //bfs(grid, row, col);
                    dfs(grid, row, col);
                }
            }
        }

        return result;
    }
};
```

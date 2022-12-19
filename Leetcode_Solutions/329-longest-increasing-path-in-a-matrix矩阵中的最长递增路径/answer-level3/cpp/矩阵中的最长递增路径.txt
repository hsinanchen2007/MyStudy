### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0) {
            return 0;
        }
        int column = matrix[0].size();
        if (column == 0) {
            return 0;
        }
        int res = 0;
        vector<vector<int> > memory(row, vector<int>(column, 0));
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < column; ++j) {
                res = max(res, DFS(matrix, i, j, memory));
            }
        }
        return res;
    }

    int DFS(vector<vector<int>>& matrix, int row, int column, vector<vector<int> >& memory) {
        int t = 0;
        if (memory[row][column] != 0) {
            return memory[row][column];
        }
        for(int i = 0; i < 4; ++i) {
            int next_row = row + directions[i][0];
            int next_column = column + directions[i][1];
            if (next_row >= 0 && next_row < matrix.size() && next_column >= 0 && next_column < matrix[0].size() && matrix[next_row][next_column] > matrix[row][column]) {
                t = max(t, DFS(matrix, next_row, next_column, memory));

            }
        }   
        memory[row][column] = 1+t; 
        return 1+t;
    }
};
```
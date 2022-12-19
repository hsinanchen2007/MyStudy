### 解题思路
依次判断每个元素的周围的活细胞数目，然后根据当前元素的值和活细胞的数目得到一个新的二维数组，最后替换原有的二维数组

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> next;
        int line_size = board.size();
        int col_size;
        for (int i = 0; i < line_size; ++i) {
            vector<int> line;
            col_size = board[i].size();

            for (int j = 0; j < col_size; ++j) {
                int live_cell_number = 0;
                if (i > 0) {
                    if (j > 0 && board[i-1][j-1] == 1) {
                        // left-top
                        live_cell_number++;
                    }
                    
                    if (board[i-1][j] == 1) {
                        // top
                        live_cell_number++;
                    }

                    if (j < col_size - 1 && board[i-1][j+1] == 1) {
                        // right-top
                        live_cell_number++;
                    }
                }

                if (j > 0 && board[i][j-1] == 1) {
                    // left
                    live_cell_number++;
                }

                if (j < col_size - 1 && board[i][j+1] == 1) {
                    // right
                    live_cell_number++;
                }

                if (i < line_size - 1) {
                    if (j > 0 && board[i+1][j-1] == 1) {
                        // left-bottom
                        live_cell_number++;
                    }

                    if (board[i+1][j] == 1) {
                        // bottom
                        live_cell_number++;
                    }

                    if (j < col_size - 1 && board[i+1][j+1] == 1) {
                        // right-bottom
                        live_cell_number++;
                    }
                }
                
                //printf("i = %d, j = %d, board[i][j] = %d, live_cell_number = %d\n", i, j, board[i][j], live_cell_number);
                if (board[i][j] == 1) {
                    if (live_cell_number == 2 || live_cell_number == 3) {
                        line.push_back(1);
                    } else {
                        line.push_back(0);
                    }
                } else {
                    if (live_cell_number == 3) {
                        line.push_back(1);
                    } else {
                        line.push_back(board[i][j]);
                    }
                }
            }

            next.push_back(line);
        }

        for (int i = 0; i < next.size(); ++i) {
            for (int j = 0; j < next[i].size(); ++j) {
                board[i][j] = next[i][j];
            }
        } 
    }
};
```
这里只是强调cpp题解中的引用

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<unordered_set<char>> rows;
        vector<unordered_set<char>> columns;
        vector<unordered_set<char>> boxes;
        int nrows = board.size();
        int ncolumns = board[0].size();

        for (int i = 0; i < nrows; i += 1) {
            rows.push_back(unordered_set<char>());
            columns.push_back(unordered_set<char>());
            boxes.push_back(unordered_set<char>());
        }

        int each = 3;
        for (int i = 0; i < nrows; i += 1) {
            unordered_set<char> &row_set = rows[i];
            for (int j = 0; j < ncolumns; j += 1) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }
                unordered_set<char> &column_set = columns[j];
                unordered_set<char> &box_set = boxes[(i / each) * each + j / each];

                if (column_set.find(c) == column_set.end()) {
                    column_set.insert(c);
                } else {
                    return false;
                }

                if (row_set.find(c) == row_set.end()) {
                    row_set.insert(c);
                } else {
                    return false;
                }

                if (box_set.find(c) == box_set.end()) {
                    box_set.insert(c);
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
```
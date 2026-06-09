没有技巧一把梭

```
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0) return res;
        int row = 0, column = 0, maxRow = matrix.size() - 1, maxColumn = matrix[0].size() - 1;
        bool up = true;
        while (true) {
            res.push_back(matrix[row][column]);
            if (up) {
                if (row > 0 && column < maxColumn) {
                    --row;
                    ++column;
                } else if (row >= 0 && row < maxRow && column == maxColumn) {
                    ++row;
                    up = !up;
                } else if (row == 0 && column < maxColumn) {
                    ++column;
                    up = !up;
                } else {
                    break;
                }
            } else {
                if (column > 0 && row < maxRow) {
                    --column;
                    ++row;
                } else if (column >= 0 && column < maxColumn && row == maxRow) {
                    ++column;
                    up = !up;
                } else if (column == 0 && row < maxRow) {
                    ++row;
                    up = !up;
                } else {
                    break;
                }
            }
        }
        return res;
    }
};
```

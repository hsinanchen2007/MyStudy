// 首先看完题目后我的第一想法是可以使用递归算法来求解：
// ```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        return getMinPathSum(grid, 0, 0);
    }

   int getMinPathSum(const vector<vector<int>>& grid, int posX, int posY) {
        if(posX == grid.size() - 1 && posY == grid[0].size() - 1)
            return grid[posX][posY];
        else {
            int currentValue = grid[posX][posY];
            int rightValue = INT_MAX;
            int bottomValue = INT_MAX;
            if(posX + 1 < grid.size())
                bottomValue = getMinPathSum(grid, posX + 1, posY);
            if(posY + 1 < grid[0].size())
                rightValue = getMinPathSum(grid, posX, posY + 1);
            return min(bottomValue, rightValue) + currentValue;
        }
    }
};
// ```
// 测试用例没有问题，但提交的时候却超时，之后看了看递归过程，从二维数组中某个点递归到右下角的那个点的路径可能被多次访问，但每次都需要重新递归，所以考虑使用记忆数组来记录这些重复的子过程。
// ```

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;

        row = grid.size();
        col = grid[0].size();
        minValue = vector<vector<int>>(row,vector<int>(col, INT_MAX));
        minValue[row - 1][col - 1] = grid[row - 1][col - 1];

        return getMinPathSum(grid, 0, 0);
    }

   int getMinPathSum(const vector<vector<int>>& grid, int posX, int posY) {
        if(minValue[posX][posY] != INT_MAX)
            return minValue[posX][posY];
        else {
            int currentValue = grid[posX][posY];
            int rightValue = INT_MAX;
            int bottomValue = INT_MAX;
            if(posX + 1 < row) {
                if(minValue[posX + 1][posY] != INT_MAX)
                    bottomValue = minValue[posX + 1][posY];
                else {
                    bottomValue = getMinPathSum(grid, posX + 1, posY);
                    minValue[posX + 1][posY] = bottomValue;
                }
            }

            if(posY + 1 < col){
                if(minValue[posX][posY + 1] != INT_MAX)
                    rightValue = minValue[posX][posY + 1];
                else {
                    rightValue = getMinPathSum(grid, posX, posY + 1);
                    minValue[posX][posY] = rightValue;
                }

            }
            int res = min(bottomValue, rightValue) + currentValue;
            minValue[posX][posY] = res;
            return res;
        }
    }

private:
    vector<vector<int>> minValue;
    int row, col;
};
// ```

// 执行用时 :24 ms, 在所有 C++ 提交中击败了9.61%的用户
// 内存消耗 :8.9 MB, 在所有 C++ 提交中击败了100.00%的用户

// 应该还可以继续优化，但没有思路了😂
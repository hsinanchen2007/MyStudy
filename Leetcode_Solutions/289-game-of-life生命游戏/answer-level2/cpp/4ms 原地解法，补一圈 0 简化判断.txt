 核心思路：
 首先在 board 周围补一圈 0 来避免处理边界情况，
 然后对 board 中的每一个元素遍历以之为中心的九宫格，计算周围的细胞数，
 根据周围细胞数决定要不要改变状态，
 需要（活->死）变化的标记为 2，
 需要（死->活）变化的标记为 -1，
 最后去掉辅助的一圈 0，更新矩阵状态。
```
class Solution {
public:
    void help(vector<vector<int>>& board) {
        int length = (int)board[0].size();
        for (auto &array : board) {
            array.insert(array.begin(), 0);
            array.push_back(0);
        }
        vector<int> barrier = vector<int>(length+2, 0);
        board.insert(board.begin(), barrier);
        board.push_back(barrier);
    }
    
    void unHelp(vector<vector<int>>& board) {
        board.erase(board.begin());
        board.pop_back();
        for (auto &array : board) {
            array.erase(array.begin());
            array.pop_back();
        }
    }
    
    bool change(int row, int col, vector<vector<int>>& board) {
        int i, j;
        i = row-1;
        
        int count = 0;
        while (i <= row+1) {
            j = col-1;
            while (j <= col+1) {
                count += board[i][j] > 0 ? 1 : 0;
                j++;
            }
            i++;
        }
        count -= board[row][col];
        if (board[row][col] <= 0) return count == 3 ? true : false;
        else return (count == 2 || count == 3) ? false : true;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        // 先记录矩阵的行列数
        int m = (int)board.size();
        int n = (int)board[0].size();
        // 补一圈 0
        help(board);
        // 标记各位置的状态是否需要更新
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (change(i, j, board)) {
                    if (board[i][j] == 1) board[i][j] += 1;
                    else board[i][j] -= 1;
                }
            }
        }
        // 去除辅助的一圈 0
        unHelp(board);
        // 更新各位置状态
        for (auto &array : board) {
            for (auto &num : array) {
                if (num > 1) num = 0;
                if (num < 0) num = 1;
            }
        }
    }
};
```

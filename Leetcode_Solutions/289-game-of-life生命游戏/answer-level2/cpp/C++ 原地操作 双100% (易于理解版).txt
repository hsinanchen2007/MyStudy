![Capture.PNG](https://pic.leetcode-cn.com/b5fe74ca2d1eeeba837733e15d5ba15e6073525f9fe72f33a6d56839ffd5dc77-Capture.PNG)

### 解题思路
定义一个`getLives()`函数, 用于统计当前cell的live neighbor数, 以正负号, 即`flag`表示该cell是否存活, 由于`1`和`0`的周围都是`0`时都会得到`0`, 故计算出来的`getLives()`需要加`1`以示区别, 因此当`board[i][j] == -4`(其实是`-3`)时, 表示原状态的`board[i][j]`为`0`且其live neighbor数为`3`. 同理, 对于原状态`board[i][j] == 1`时可知, 将其更新为统计live neighbor数后, 需要加`1`, 故当`board[i][j] == 3 || board[i][j] == 4`时表示其原状态为`1`, 且live neighbor数为`2`或`3`. 最后据此再更新一遍数组, 得到结果.

### 代码

```cpp
class Solution {
private:
    int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
    
    bool isLegal(const vector<vector<int>>& board, const int& x, const int& y) const {
        int m = board.size(), n = board[0].size();
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    
    int getLives(const vector<vector<int>>& board, const int&x, const int& y) const {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isLegal(board, nx, ny) && board[nx][ny] > 0) cnt++;
        }
        return cnt;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int flag = 1;
                if (board[i][j] == 0)
                    flag = -1;
                board[i][j] = flag * (getLives(board, i, j) + 1);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -4 || board[i][j] == 3 || board[i][j] == 4)
                    board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }
};
```
### 解题思路
就是遍历每个点计算周围活细胞的数量。需要注意的两个问题：1，不能基于变化更新状态，我们可以通过复制一个snap_short来解决；2，边界问题，我原以为在边界的点可以通过镜像补齐，从test_case来看不是。

优化点：周围活细胞的数量live_cells > 3,我们即可跳出循环。

执行结果：
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :7.1 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[8] = {-1,-1,-1,0,1, 1, 1,0};
        int dy[8] = {-1, 0, 1,1,1, 0,-1,-1}; // 8 点辅助变化坐标
        auto snap_short = board;

        for (int x = 0; x < board.size(); x++) {
            for (int y = 0; y < board[0].size(); y++) {
                int status = snap_short[x][y];
                int live_cells = 0;
                for (int k = 0; k < 8; k++) {
                    int i = x + dx[k];
                    int j = y + dy[k];
    /*
                    if (i < 0)
                        i = 1;
                    else if (i == board.size()) {
                        i = board.size() - 2;
                    }
                    if (j < 0)
                        j = 1;
                    else if (j == board[0].size())
                        j = board[0].size() - 2;*/
                    if (i < 0 || i == board.size() || j < 0 || j == board[0].size())
                        continue;
                    live_cells += snap_short[i][j];
                    if (live_cells > 3)
                        break;
                }

                if (status > 0) {
                    if (live_cells < 2 || live_cells > 3) {
                        board[x][y] = 0;
                    }
                }
                else {
                    if (live_cells == 3) {
                        board[x][y] = 1;
                    }
                }
            }
        }
        return;
    }
};
```
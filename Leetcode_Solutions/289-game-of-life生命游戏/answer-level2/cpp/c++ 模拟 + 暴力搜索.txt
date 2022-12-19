### 解题思路
**模拟 + 暴力搜索**:
- 这里需要注意要求的是下一时刻的状态，
- 所以不能直接在原始`board`上修改. 否则会把修改后的新状态引入进去.
- 所以先对原始`board`做copy留作副本`curBoard`


### 代码

```cpp
class Solution {
public:
    int direction[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty() || board[0].empty()) return ;
        vector<vector<int>> curBoard(board);
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
        {
            int liveCount = 0;
            // live number count
            for (int k = 0; k < 8; ++k)
            {
                int tmpRow = direction[k][0] + i, tmpCol = direction[k][1] + j;
                if (0 <= tmpRow && tmpRow < m && 0 <= tmpCol && tmpCol <n)
                {
                    if (curBoard[tmpRow][tmpCol] == 1) liveCount++;
                }
            }
            if (curBoard[i][j] == 1) // alive cell. 
            {
                if (liveCount < 2 || liveCount > 3) board[i][j] = 0;
            }          
            else // death cell
            {
                if (liveCount == 3) board[i][j] =1;
            }
        }
        return ;
    }
};
```
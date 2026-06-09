### 解题思路
设周边或细胞数为nAlive
1. 细胞死亡: nAlive < 2 || nAlive > 3
2. 细胞存活状态不变: nAlive == 3 || nAlive == 2
3. 细胞复活: nAlive == 3

构造周边细胞索引:
int index[MAX_AROUND][2] = {
    {-1, -1},   // left-up
    {-1, 0},    // up
    {-1, 1},    // right-up
    {0, 1},     // right
    {1, 1},     // right-down
    {1, 0},     // down
    {1, -1},    // left-down
    {0, -1},    // left
};
遍历一遍vector,根据周边alive数量即可得出

### 代码

```cpp
class Solution {
public:
    void gameOfLife(std::vector<std::vector<int>>& board)
    {
    #define MAX_AROUND 8
        int index[MAX_AROUND][2] = {
            {-1, -1},   // left-up
            {-1, 0},    // up
            {-1, 1},    // right-up
            {0, 1},     // right
            {1, 1},     // right-down
            {1, 0},     // down
            {1, -1},    // left-down
            {0, -1},    // left
        };

        auto get_alive_state = [](int nAlive, int curState)
        {
            if (nAlive < 2 || nAlive > 3)
                return 0;
            else if (nAlive == 3)
                return 1;
            return curState;
        };

        int maxrow = board.size();
        int maxcol = board[0].size();
        std::vector<std::vector<int>> newvec = board;
        for (int row = 0; row < maxrow; ++row)
        {
            for (int col = 0; col < maxcol; ++col)
            {
                // 查找每个细胞周边细胞
                int count = 0;
                int tmprow = 0, tmpcol = 0;
                for (int i = 0; i < MAX_AROUND; ++i)
                {
                    if ((tmprow = row + index[i][0]) < 0 || (tmpcol = col + index[i][1]) < 0
                        || tmprow >= maxrow || tmpcol >= maxcol)
                        continue;
                    if (board[tmprow][tmpcol] == 1)
                        ++count;
                }
                newvec[row][col] = get_alive_state(count, board[row][col]);
            }
        }

        board = newvec;
    }
};
```
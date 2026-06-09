### 解题思路

关于额外空间解法：
1. 遍历第一次，对每个位置的细胞：
- 判断该位置本轮中周围存活的邻居细胞数量：若邻居细胞值为1或者3，则该邻居本轮存活
- 判断该位置细胞下轮是否存活：
    - 若该位置为0，下一轮不存在，则该位置值不变；若下一轮存在，则将值加2，改为2
    - 若该位置为1，下一轮不存在，则该位置值不变；若下一轮存在，则将值加2，改为3
2. 遍历第二次，对每个位置的细胞：
- 若值大于1，则该位置细胞下轮存活，将值改为1；否则将其改为0

3. 值具体对应的含义：
- 0：本轮与下轮都不存在
- 1：本轮存在，下轮不存在
- 2：本轮不存在，下轮存在
- 3： 本轮与下轮都存在

### 代码

```cpp []
class Solution {
public:
    int getLiveNeighborNum(const vector<vector<int>>& board, int r, int c)
    {
        int res = 0, nr, nc;
        int m = board.size();
        int n = board[0].size();
        int drct[2][8] ={{-1, -1, -1, 0, 0, 1, 1, 1}, {-1, 0, 1, -1, 1, -1, 0, 1}}; 
        for(int i = 0; i < 8; i++)
        {
            nr = r + drct[0][i];
            nc = c + drct[1][i];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc]) res++;
        }
        return res;
    }
    //额外空间解法
    void gameOfLife(vector<vector<int>>& board) {
        auto copy = board;
        int num = 0;
        for(int r = 0; r < copy.size(); r++)
            for(int c = 0; c < copy[0].size(); c++)
            {
                num = getLiveNeighborNum(copy, r, c);
                board[r][c] = num == 3 || (num == 2 && copy[r][c] == 1);
            }
    }
};
```
```cpp []
class Solution {
public:
    int getCurNeighborNum(const vector<vector<int>>& board, int r, int c)
    {
        int res = 0, nr, nc;
        int m = board.size();
        int n = board[0].size();
        int drct[2][8] ={{-1, -1, -1, 0, 0, 1, 1, 1}, {-1, 0, 1, -1, 1, -1, 0, 1}}; 
        for(int i = 0; i < 8; i++)
        {
            nr = r + drct[0][i];
            nc = c + drct[1][i];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc]%2) res++;
        }
        return res;
    }
    //原地解法
    void gameOfLife(vector<vector<int>>& board) {
        int num = 0;
        for(int r = 0; r < board.size(); r++)
            for(int c = 0; c < board[0].size(); c++)
            {
                num = getCurNeighborNum(board, r, c);
                if(num == 3 || (num == 2 && board[r][c] == 1)) board[r][c] += 2;
            }
        for(int r = 0; r < board.size(); r++)
            for(int c = 0; c < board[0].size(); c++)
                board[r][c] = board[r][c] > 1; 
    }
};
```
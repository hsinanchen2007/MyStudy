### 执行时间
![图片.png](https://pic.leetcode-cn.com/6a49ebbc1a3a5c952cfee5d547544a66066479ae2bcbefabfbef946814b7f81c-%E5%9B%BE%E7%89%87.png)

### 思路
1. 第一次遍历时，作为活细胞要主动报告给周围的 8 个细胞。
   11. 接收方如果是活细胞 +1 ， 死细胞 -1 
   12. 这样就可以用正负值来区分原来是活还是死。
   > 全部标记后，如果之前是活的，数值就为正，数字代表**包含自己**和周围 8 个格子活细胞数量。
   > 全部标记后，如果之前是死的，数值就为负，数字就是负的周围 8 个格子活细胞数量。

2. 第二次遍历时，根据统计的数量重置为 0 和 1 。
    21. 如果之前是活的，判断周围有 2 个或 3 个活细胞，即统计数量为 3 或 4 ，活下来。
    22. 如果之前是死的，判断周围有 3 个活细胞，即统计数量为 -3 ，活下来。

3. 使用 `aliveReport()` 报告给周围 8 个格子中的合法格子集合。

### 答题
```C++
void aliveReport(vector<vector<int>>& board, int x, int y)
{
    for (int i = max(0, x - 1); i < min((int)board.size(), x + 2); i++)
    {
        for (int j = max(0, y - 1); j < min((int)board[0].size(), y + 2); j++)
        {
            if (i == x && j == y) continue;
            board[i][j] += (board[i][j] > 0) ? 1 : -1;
        }
    }
}

void gameOfLife(vector<vector<int>>& board)
{
    if (board.empty() || board[0].empty()) return;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] <= 0) continue;
            aliveReport(board, i, j);
        }
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            int& x = board[i][j];
            x = (x == 2 + 1 || x == 3 + 1 || x == -3) ? 1 : 0;
        }
    }
}
```

### 其他方式
1. 也可以使用位来保存
2. 当遍历到一个细胞时，将它左移一位，然后根据周围的活细胞数量，在最右一位填写今天的状态
3. 此时最右一位就是今天的状态，左边一位是昨天的
4. 使用 `countAlive()` 来计算周围有多少个活细胞，通过索引可以知道哪些是前面的细胞，已经把状态转移了
5. 全部改变状态之后，再全部修改为今天的状态

### 答题
```C++ []
int countAlive(vector<vector<int>>& board, int x, int y)
{
    int cnt = 0;
    for (int i = max(0, x - 1); i < min((int)board.size(), x + 2); i++)
    {
        for (int j = max(0, y - 1); j < min((int)board[0].size(), y + 2); j++)
        {
            if (i == x && j == y) continue;
            cnt += (i < x || (i == x && j < y)) ? ((0b10 & board[i][j]) != 0) : ((0b01 & board[i][j]) != 0);
        }
    }
    return cnt;
}

void gameOfLife(vector<vector<int>>& board)
{
    if (board.empty() || board[0].empty()) return;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            int cnt = countAlive(board, i, j);
            board[i][j] <<= 1;
            if ((board[i][j] & 0b10) != 0)
            {
                board[i][j] |= (cnt == 2 || cnt == 3);
            }
            else
            {
                board[i][j] |= (cnt == 3);
            }
        }
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            board[i][j] &= 1;
        }
    }
}
```


### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)



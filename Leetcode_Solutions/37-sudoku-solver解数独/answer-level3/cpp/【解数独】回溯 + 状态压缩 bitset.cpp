### 思路
1. 回溯
    11. 选择可能性最少的数字开始填，填错了回溯

2. 状态压缩
    21. 使用 `bitset<9>` 来压缩存储每一行、每一列、每一个 `3x3` 宫格中 `1-9` 是否出现
    22. 这样每一个格子就可以计算出所有能填的数字
    23. 填入数字和回溯时，只需要更新存储信息，各个格子会重新计算其各自的能填数字

### 图解
![图片.png](https://pic.leetcode-cn.com/1fb1c64cfddb5c66b61bd769224724a05027172d6486feb19b3a16d9473372ee-%E5%9B%BE%E7%89%87.png)


### 答题
```C++ []
class Solution {
public:
    bitset<9> getPossibleStatus(int x, int y)
    {
        return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);
    }

    vector<int> getNext(vector<vector<char>>& board)
    {
        vector<int> ret;
        int minCnt = 10;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] != '.') continue;
                auto cur = getPossibleStatus(i, j);
                if (cur.count() >= minCnt) continue;
                ret = { i, j };
                minCnt = cur.count();
            }
        }
        return ret;
    }

    void fillNum(int x, int y, int n, bool fillFlag)
    {
        bitset<9> pick(1 << n);
        rows[x] = (fillFlag) ? (rows[x] | pick) : (rows[x] ^ pick);
        cols[y] = (fillFlag) ? (cols[y] | pick) : (cols[y] ^ pick);
        cells[x / 3][y / 3] = (fillFlag) ? (cells[x / 3][y / 3] | pick) : (cells[x / 3][y / 3] ^ pick);
    }
    
    bool dfs(vector<vector<char>>& board, int cnt)
    {
        if (cnt == 0) return true;

        auto next = getNext(board);
        auto bits = getPossibleStatus(next[0], next[1]);
        for (int n = 0; n < bits.size(); n++)
        {
            if (!bits.test(n)) continue;
            fillNum(next[0], next[1], n, true);
            board[next[0]][next[1]] = n + '1';
            if (dfs(board, cnt - 1)) return true;
            board[next[0]][next[1]] = '.';
            fillNum(next[0], next[1], n, false);
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) 
    {
        rows = vector<bitset<9>>(9, bitset<9>());
        cols = vector<bitset<9>>(9, bitset<9>());
        cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));

        int cnt = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                cnt += (board[i][j] == '.');
                if (board[i][j] == '.') continue;
                int n = board[i][j] - '1';
                rows[i] |= (1 << n);
                cols[j] |= (1 << n);
                cells[i / 3][j / 3] |= (1 << n);
            }
        }
        dfs(board, cnt);
    }

private:
    vector<bitset<9>> rows;
    vector<bitset<9>> cols;
    vector<vector<bitset<9>>> cells;
};
```

### 执行时间
![图片.png](https://pic.leetcode-cn.com/966e84833b639c749bf0f62d51d49959ed848393a62b69567008c491dbf3037e-%E5%9B%BE%E7%89%87.png)


### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)


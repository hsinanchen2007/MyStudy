### 思路
1. 先确定 `R` 的位置
2. 然后对上下左右四个方向进行搜索
    21. 遇到 `.` 就继续找
    22. 遇到 `B` 就停止找
    23. 越界就停止
    24. 遇到 `p` 就停止找，计数加一

### 方法
既然这道题目的这么明确，就用来熟悉方向数组吧。
定义上下左右的坐标偏移值，就可以在循环中操作。
扩展到八个方向也可以哦~~

### 答题
```C++
int getp(vector<vector<char>>& b, int x, int y)
{
    vector<vector<int>> dd = {{0,1},{0,-1},{1,0},{-1,0}};

    int cnt = 0;
    for (auto d : dd)
    {
        int dx = x;
        int dy = y;
        while (true)
        {
            dx += d[0];
            dy += d[1];
            if (dx < 0 || dx >= b.size()) break;
            if (dy < 0 || dy >= b[0].size()) break;
            if (b[dx][dy] == 'B') break;
            if (b[dx][dy] == 'p') 
            {
                cnt++;
                break;
            }  
        }
    }
    return cnt;
}

int numRookCaptures(vector<vector<char>>& board)
{
    for (int x = 0; x < board.size(); x++)
    {
        for (int y = 0; y < board[0].size(); y++)
        {
            if (board[x][y] != 'R') continue;
            return getp(board, x, y);
        }
    }
    return 0;
}
```



### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)


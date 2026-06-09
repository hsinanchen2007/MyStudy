### 思路
1. 定义通路的方向
    11. 上方的通路为 `0`
    12. 右方的通路为 `1`
    13. 下方的通路为 `2`
    14. 左方的通路为 `3`
2. 定义方向数组
3. 从起点开始，沿着合法的路走
4. 通过 `grid` 数据，转化成通路的方向，检查来的方向是否有效
    41. 因为上一个格子的去路和这个格子的来路有 180° 关系，所以通过 `(dir_cur + 2) % 4 == path` 判断
5. 沿着去的方向走到下一个格子

### 答题
```C++ []
bool hasValidPath(vector<vector<int>>& grid) 
{
    if (grid.size() == 1 && grid[0].size() == 1) return true;

    vector<vector<int>> dpath = { {}, {1, 3}, {0, 2}, {3, 2}, {2, 1}, {0, 3}, {0, 1} };
    vector<vector<int>> dd = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

    queue<int> que;
    for (auto dir_cur : dpath[grid[0][0]])
    {
        if (dir_cur == 0 || dir_cur == 3) continue;
        int x = 0;
        int y = 0;

        while (true)
        {
            x += dd[dir_cur][0];
            y += dd[dir_cur][1];
            if (x < 0 || x >= grid.size()) break;
            if (y < 0 || y >= grid[0].size()) break;

            bool enter = false;
            int dir_nxt = -1;
            for (auto& path : dpath[grid[x][y]])
            {
                if ((dir_cur + 2) % 4 == path)
                {
                    enter = true;
                    continue;
                }
                dir_nxt = path;
            }
            if (!enter) return false;

            if (x == grid.size() - 1 && y == grid[0].size() - 1) return true;
            dir_cur = dir_nxt;
        }
    }
    return false;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)


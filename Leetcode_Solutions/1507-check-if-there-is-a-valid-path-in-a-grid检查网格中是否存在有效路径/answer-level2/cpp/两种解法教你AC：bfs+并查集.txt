## 分析
__街道：把街道两侧的两个点（不包括街道所在的点）连接起来__

![20200322212949.png](https://pic.leetcode-cn.com/a03ddded5aa8f525b00ddfb9d4d9968264a060a0e857d2d6a8cad978e23fc6fb-file_1584886537595)
如图所示，左上角的街道`(0,0)`将两个点`(0,-1)`,`(0,1)`连接起来

加到队列里面的是点，不是街道
定义完街道以后，可以开始遍历了，从左上角`(0,0)`开始bfs，看看当前点的街道把哪两个点连在一起了？

这里我加了两个数组简化程序,其中第0位是没用的，后面的第i位对应第i类街道
```
int xdir[7][2] = {{0, 0}, {1, -1}, {0, 0}, {-1, 0}, {1, 0}, {-1, 0}, {1, 0}};
int ydir[7][2] = {{0, 0}, {0, 0}, {-1, 1}, {0, 1}, {0, 1}, {0, -1}, {0, -1}};
等价于
switch (grid[y][x])
{
case 1:
    q.push(make_pair(x + 1, y));
    q.push(make_pair(x - 1, y));
    break;
case 2:
    q.push(make_pair(x, y - 1));
    q.push(make_pair(x, y + 1));
    break;
case 3:
    q.push(make_pair(x - 1, y));
    q.push(make_pair(x, y + 1));
    break;
case 4:
    q.push(make_pair(x + 1, y));
    q.push(make_pair(x, y + 1));
    break;
case 5:
    q.push(make_pair(x - 1, y));
    q.push(make_pair(x, y - 1));
    break;
case 6:
    q.push(make_pair(x + 1, y));
    q.push(make_pair(x, y - 1));
}
```

但是光这样写不能AC，最后三个点过不去，为什么呢？  

看一看数据:
```
[[1,1,2]]
横横竖
```
第二个点把第一和第三个点连起来了，但是第三个点是到不了第二个点的  
所以我们不仅要判断从第一个点能否到第三个点，还要判断从第三个点能否回到第一个点

那就算一算呗：由当前点可以推出被当前点所在街道连接的两个点`a,b`，由`a`点所在的街道又可以推回来，看一看能否到达当前点,`b`点同理，也判断一次。  
这样就能够保证该条街道是双向的了。

```
倒推回当前点的时候，要判断两个点，因为一条街道连接两个点，当前点可能是其中的一个
if (make_pair(x, y) == calNxt(grid, nx, ny, 0) || make_pair(x, y) == calNxt(grid, nx, ny, 1))
{
    q.push(make_pair(nx, ny));
}
```
## `unordered_set`
这个是用来查重的，就是一个存了`pair`的hash函数  
重载hash函数那里我也不太懂，是抄别人的，可以上去看看[官方文档](https://zh.cppreference.com/w/cpp/container/unordered_set)

```
当找不到now的时候,mark.find(now)会返回mark.end()
找到now就说明这个点之前已经遍历过了，于是跳过它

if (mark.find(now) != mark.end())
    continue;
```
## code
448 ms	55.5 MB

双百（是因为交的人少）
```
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int xdir[7][2] = {{0, 0}, {1, -1}, {0, 0}, {-1, 0}, {1, 0}, {-1, 0}, {1, 0}};
    int ydir[7][2] = {{0, 0}, {0, 0}, {-1, 1}, {0, 1}, {0, 1}, {0, -1}, {0, -1}};
    int n, m;
    struct HashPair
    {
        size_t operator()(const pair<int, int> &key) const noexcept
        {
            return size_t(key.first) * 100000007 + key.second;
        }
    };
    pair<int, int> calNxt(vector<vector<int>> &grid, int x, int y, int i)
    {
        int res = grid[y][x];
        int nx = x + xdir[res][i], ny = y + ydir[res][i];
        return make_pair(nx, ny);
    }
    bool hasValidPath(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        queue<pair<int, int>> q;
        unordered_set<pair<int, int>, HashPair> mark;
        q.push(make_pair(0, 0));
        auto ans = make_pair(m - 1, n - 1);
        while (!q.empty())
        {
            auto now = q.front();
            q.pop();
            if (now == ans)
            {
                return true;
            }
            int x = now.first, y = now.second;
            // 这个点走过了
            if (mark.find(now) != mark.end())
                continue;
            mark.insert(now);
            for (int i = 0; i <= 1; i++)
            {
                auto [nx, ny] = calNxt(grid, x, y, i);
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                {
                    continue;
                }
                if (make_pair(x, y) == calNxt(grid, nx, ny, 0) || make_pair(x, y) == calNxt(grid, nx, ny, 1))
                {
                    q.push(make_pair(nx, ny));
                }
            }
        }
        return false;
    }
};
```
## 并查集？
根据分析，一条街道就是把两个点连接起来，问题就是求`(0,0)`和`(m-1,n-1)`是否连通

这不就可以用并查集了吗？

如果当前点所在的街道是双向的，就合并该街道两端的点。  
最后查询`(0,0)`和`(m-1,n-1)`的祖先是否相等  
相等就说明两个点连通

### code
264 ms	24.2 MB	

这个更快，更省空间哦  

```
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    int xdir[7][2] = {{0, 0}, {1, -1}, {0, 0}, {-1, 0}, {1, 0}, {-1, 0}, {1, 0}};
    int ydir[7][2] = {{0, 0}, {0, 0}, {-1, 1}, {0, 1}, {0, 1}, {0, -1}, {0, -1}};
    int f[90005];
    pair<int, int> calNxt(vector<vector<int>> &grid, int x, int y, int i)
    {
        int res = grid[y][x];
        int nx = x + xdir[res][i], ny = y + ydir[res][i];
        return make_pair(nx, ny);
    }
    int find(int x)
    {
        if (x == f[x])
            return x;
        f[x] = find(f[x]);
        return f[x];
    }
    void merge(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if (fx != fy)
        {
            f[fx] = fy;
        }
    }
    bool hasValidPath(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 1; i <= n * m; i++)
        {
            f[i] = i;
        }
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                for (int i = 0; i <= 1; i++)
                {
                    auto [nx, ny] = calNxt(grid, x, y, i);
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    {
                        continue;
                    }
                    if (make_pair(x, y) == calNxt(grid, nx, ny, 0) || make_pair(x, y) == calNxt(grid, nx, ny, 1))
                    {
                        merge(x + y * m, nx + ny * m);
                    }
                }
            }
        }
        int st = 0, end = (n - 1) * m + m - 1;
        if (find(st) == find(end))
            return true;
        return false;
    }
};
```
## 题后总结
其实这道题我比赛的时候也没有做出来，过一会再做就想出来了，看来还是比赛经验不足，紧张了
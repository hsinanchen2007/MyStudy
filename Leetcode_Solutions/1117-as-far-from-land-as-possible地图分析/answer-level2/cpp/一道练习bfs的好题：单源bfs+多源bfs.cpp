# [多源最短路](https://leetcode-cn.com/problems/as-far-from-land-as-possible/)
你现在手里有一份大小为 N x N 的『地图』（网格） grid，上面的每个『区域』（单元格）都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地，你知道距离陆地区域最远的海洋区域是是哪一个吗？请返回该海洋区域到离它最近的陆地区域的曼哈顿距离。

## 单源bfs
+ 从每个陆地出发，更新每个海洋到陆地的最短距离
+ 从每个海洋出发找离它最近的陆地

这两种单源bfs跑起来都有点慢，需要注意优化常数才能AC，有兴趣的可以看看官方题解中的常数优化  
1768 ms	252.5 MB
```cpp
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
class Solution
{
public:
    int dire[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;
    bool visited[105][105];
    vector<vector<int>> a;
    struct node
    {
        int x, y, step;
    };
    int findNearestIsland(int i, int j)
    {
        queue<node> q;
        memset(visited, 0, sizeof(visited));
        visited[i][j] = 1;
        q.push({i, j, 0});
        while (!q.empty())
        {
            node now = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = now.x + dire[i][0], ny = now.y + dire[i][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if (visited[nx][ny])
                    continue;
                // find the nearest island
                if (a[nx][ny])
                    return now.step + 1;
                visited[nx][ny] = 1;
                q.push({nx, ny, now.step + 1});
            }
        }
        return -1;
    }
    int maxDistance(vector<vector<int>> &grid)
    {
        int ans = -1;
        n = grid.size();
        m = grid[0].size();
        a = grid;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!grid[i][j])
                {
                    ans = max(ans, findNearestIsland(i, j));
                }
            }
        }
        return ans;
    }
};
``` 
## [多源bfs](https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/zhen-liang-yan-sou-huan-neng-duo-yuan-kan-wan-miao/)
先把每个陆地加到队列里面，再一起bfs

多源bfs=以超级源点为第一层，多个选出来的源点为第二层进行bfs

![多源bfs](https://pic.leetcode-cn.com/5d4d1debe4c272fc248d67b9eeda8f2f8e530bc35a38c286bf3e6b8285e85859-%E8%B6%85%E7%BA%A7%E6%BA%90%E7%82%B9.png)

多源bfs明显比单源bfs快很多  
324 ms	32.4 MB
```cpp
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int dis[105][105];
        bool visited[105][105];
        int inf = 1 << 30;
        for (int x = 0; x < grid.size(); x++)
            for (int y = 0; y < grid[0].size(); y++)
                visited[x][y] = false;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                dis[i][j] = inf;
            }
        }
        queue<tuple<int, int, int>> q;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j])
                {
                    q.push(make_tuple(i, j, 0));
                }
            }
        }
        while (!q.empty())
        {
            auto [x, y, step] = q.front();
            q.pop();
            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
                continue;
            if (visited[x][y])
                continue;
            visited[x][y] = 1;
            if (!grid[x][y])
                dis[x][y] = min(dis[x][y], step);
            // reach another island
            if (grid[x][y] && step > 0)
                continue;
            q.push(make_tuple(x + 1, y, step + 1));
            q.push(make_tuple(x - 1, y, step + 1));
            q.push(make_tuple(x, y + 1, step + 1));
            q.push(make_tuple(x, y - 1, step + 1));
        }
        int ans = -1;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (dis[i][j] == inf)
                    dis[i][j] = -1;
                ans = max(ans, dis[i][j]);
            }
        }
        return ans;
    }
};
```
还可以进一步优化：
+ 删掉visited数组，填海造陆，访问过的ocean变成island
+ 删掉dis数组，在bfs中记录当前步数（重点）

怎么在bfs中记录当前步数呢？  
将问题转化为：怎样在bfs中区分当前层与下一层?

加入一个`size`变量记录第一次遍历到当前层时的队列长度，即为当前层的元素个数。同一层的步数相等，只有遍历完同一层后才进行`step++`更新步数。

这样划分层数合理的原因是：队列中同一层的聚在一起，下一层的一定在它们后面

注意最后`step-1`，因为在判断到队列为空之前，在最后一层bfs中`step`会多加一次。

优化后效果  
112 ms	16.4 MB
```cpp
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
class Solution
{
public:
    int dis[105][105];
    int dire[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int maxDistance(vector<vector<int>> &grid)
    {
        int inf = 1 << 30;
        int n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    q.push(make_pair(i, j));
                }
            }
        }
        // all islands or all ocean
        if (q.size() == n * n || q.size() == 0)
            return -1;
        int step = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                pair<int, int> now = q.front();
                int x = now.first;
                int y = now.second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int nxt_x = x + dire[i][0];
                    int nxt_y = y + dire[i][1];
                    if (nxt_x < 0 || nxt_x >= n || nxt_y < 0 || nxt_y >= n)
                        continue;
                    if (!grid[nxt_x][nxt_y])
                    {
                        // 填海造陆
                        grid[nxt_x][nxt_y] = 1;
                        q.push(make_pair(nxt_x, nxt_y));
                    }
                }
            }
            step++;
        }
        // why step-1?
        // 在最后一层bfs中step会多加一次,在判断到队列为空之前
        return step - 1;
    }
};
```
## 多源最短路
第一次见到dijkstra能用来求多源最短路的


详见[官方题解](https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/di-tu-fen-xi-by-leetcode-solution/)

这里以 Dijkstra 算法为例，我们知道堆优化的 Dijkstra 算法实际上是 BFS 的一个变形，把 BFS 中的队列变成了优先队列，在拓展新状态的时候加入了松弛操作。Dijkstra 的堆优化版本第一步是源点入队，我们只需要把它改成源点集合中的所有的点入队就可以实现求「多源最短路」。

[无效的图片地址](https://raw.githubusercontent.com/doutv/Picbed/master/img/3-29-2020-03-29-21-25-40)

但是根据[官方题解](https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/di-tu-fen-xi-by-leetcode-solution/)的分析，该算法的时间复杂度比多源bfs高
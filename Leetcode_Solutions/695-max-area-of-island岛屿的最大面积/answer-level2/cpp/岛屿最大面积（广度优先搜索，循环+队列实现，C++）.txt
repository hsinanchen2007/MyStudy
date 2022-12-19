**方法：** 广度优先遍历（BFS）
**实现：** 循环 + 队列

啊啊啊好激动，人生中的第一篇 LeetCode 题解。

**主要思路：**
1. 从开头开始遍历地图，遇到土地（地图中为 `1`）后，把坐标加入队列；
2. 从队列取出来一块土地，计算它所在岛屿的面积。计算方法是：面积初始化为 1，上下左右搜索它四周的格子，如果是土地，那面积就加 1，并且把坐标加入队列。只要队列不为空，就不断地从队列取出新的土地，重复上述过程。直到队列为空，当前土地所在岛屿的面积就计算好了。
3. 遍历过程每遇到一块土地，都重复上述操作，遍历完成后，我们就知道岛屿的最大面积了。

**几个关键点：**
1. 为了避免重复访问同一个格子，最简单的方法就是把访问过的格子都置 `0`，不过这种方法不是很推荐，因为这样会改动原始地图，然而偷懒的我还是这么做了。当然也可以先置为一个不相关的数字，算法结束后再改回来，但说来说去，还是改动了原始地图。其实，我们可以引入一个 `set`，每访问到一个新的格子，都把它的坐标插入到 `set` 中。这样，下次遇到一块土地 B 时，我们可以快速地判断之前是否访问过它，如果没访问过，说明这是一块全新的土地，访问它！如果访问过了，那就是说，在前面曾有一块土地 A，我们搜索 A 周围时，访问到了 B，即 A 和 B 同属于一个岛屿，那这个面积我们已经计算过了，不需要重新计算了，下一个！
2. 推荐使用 `size_t` 来遍历 `vector` 表示的地图，`size_t` 实际上是无符号整数，不会小于 0，这样在判断地图越界的时候，就不需要判断 `i < 0` 的情况了。
3. 判断越界和是不是土地时，要先判断越界，再判断是不是土地，这样，如果已经越界，条件运算就会短路掉，不会再去访问不存在的地图边缘，否则如果先判断了 `grid[i][j] == 0`，遇到越界的情况，就会 `vector subscript out of range` 了。
4. 实际上，把队列换成栈，就变成了深度优先搜索（DFS）。

**C++ 代码：**
```c++
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // 异常情况
        if (grid.size() == 0)
            return 0;

        // 地图长宽
        size_t m = grid.size();
        size_t n = grid[0].size();
       
        queue<vector<size_t> > q;  // 队列, 存储将来要探索的土地坐标

        int maxArea = 0;
        int area = 0;

        // 上下左右定义探索方向
        int dx[4] = { 0, 0, -1, 1 };
        int dy[4] = { 1, -1, 0, 0 };

        // 遍历地图每一个格子
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                // 遇到一块土地后
                if (grid[i][j] == 1) {
                    q.push({ i, j });  // 将这块土地加入探索队列
                    grid[i][j] = 0;    // 标记访问过
                    area = 1;          // 岛屿面积初始化为 1
                    // 如果探索队列不为空
                    while (!q.empty()) {
                        // 从探索队列取出一块土地
                        auto v = q.front();
                        q.pop();
                        // 探索上下左右四个方向相连的格子
                        for (int d = 0; d < 4; d++) {
                            vector<size_t> next({ v[0]+dx[d], v[1]+dy[d] });
                            // 如果探索到的格子出了地图边界, 或者已经到海上了
                            // 那么放弃这个方向的探索, continue 下一个方向
                            if (next[0] >= m
                            || next[1] >= n
                            || grid[next[0]][next[1]] == 0) {
                                continue;
                            }
                            // 如果探索到新的土地
                            // 加入探索队列, 将来会立足这块土地, 继续探索
                            // 当前岛屿面积加 1
                            if (grid[next[0]][next[1]] == 1) {
                                q.push({ next[0], next[1] });
                                grid[next[0]][next[1]] = 0;
                                area++;
                            }
                        }
                    }
                    // 始终记录着目前探索到的最大的岛屿面积
                    if (maxArea < area) {
                        maxArea = area;
                    }
                }
            }
        }

        return maxIsland;
    }
};
```


PS: 膜拜了一下大佬们用 **递归** 实现的深度优先搜索（DFS），代码是真的简洁。

**C++ 代码：**
```c++
class Solution {
public:
    int inline getArea(vector<vector<int>>& grid, size_t i, size_t j) {
        // 递归终止条件:
        // 判断坐标是否到了地图边界, 或者到了海上
        if (i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return 0;
        
        // 递归本体:
        grid[i][j] = 0;  // 已阅
        // 当前土地面积算 1, 然后递归加上上下左右方向的
        return 1 + getArea(grid, i + 1, j) + getArea(grid, i - 1, j)
               + getArea(grid, i, j + 1) + getArea(grid, i, j - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int area = 0;
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    // 计算当前格子所在岛屿面积
                    area = getArea(grid, i, j);
                    maxArea = maxArea > area ? maxArea : area;
                }
            }
        }
        return maxArea;
    }
};
```

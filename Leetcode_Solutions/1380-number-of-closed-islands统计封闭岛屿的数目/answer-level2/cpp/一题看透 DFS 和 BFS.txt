- DFS 和 BFS 都是常用来遍历搜索树或图的算法。
- 二叉树中的前序、中序和后序遍历都属于DFS，层次遍历属于BFS。 
- DFS常用递归和栈来实现，BFS常用队列来实现。


#### 解题思路

- 题目要我们求出封闭岛屿的个数，那我们可以先遍历矩阵中的每一个位置，如果当前位置为0(陆地)，我们就需要判断该位置所在的岛屿是否为封闭岛屿。

- 那如何找到该位置所在的岛屿呢？当然就是从该位置出发向四个方向遍历了。这属于遍历一块区域内的所有内容，使用DFS 和 BFS 都可以。

```cpp
int closedIsland(vector<vector<int>>& grid) {
    int ret = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 0) {
                ret += dfs(grid, i, j);
                //或者使用BFS
                //ret += bfs(grid, i, j);
            }
        }
    }
    return ret;
}
```

#### DFS

- 从当前陆地开始出发，如果能走出边界就说明该陆地所在岛屿不是封闭岛屿，返回封闭岛屿个数0
```cpp
if (r < 0 || r >= grid.size() || r < 0 || c >= grid[0].size()) {
    return 0;
}
```

- 如果碰到水域(值为1的点)就返回封闭岛屿个数1，表示该岛屿可能就是一个封闭岛屿
```cpp
if (grid[r][c] == 1) { 
    return 1;
}
```

- 如果碰到陆地(值为0的点)就继续向该陆地的四个方向遍历，同时将该陆地标记为1，表示这个位置已经遍历过了。DFS代码如下

```cpp
int dfs(vector<vector<int>>& grid, int r, int c) {
    if (r < 0 || r >= grid.size() || r < 0 || c >= grid[0].size()) {
        return 0;
    }
    if (grid[r][c] == 1) {
        return 1;
    }
    grid[r][c] = 1;
    int vr[] = {0, 1, 0, -1};
    int vc[] = {1, 0, -1, 0};
    int ret = 1;
    for (int i = 0; i < 4; i++) {
        ret = min(ret, dfs(grid, r+vr[i], c+vc[i]));
    }
    return ret;
}
```

**小小在这解释一下: **
- 这里巧妙地使用了两个向量vr和vc来模拟四个方向，最后只需要一个在for循环就可以向四个方向DFS了。当然手动写四个dfs也是可以的，只是这样显得不够优雅，如果加上斜对角线有八个方向可以走呢，写八遍`dfs`就显得很累赘了。
```cpp
dfs(grid, r, c+1);
dfs(grid, r+1, c);
dfs(grid, r-1, c);
dfs(grid, r, c-1);
```

- 为什么要使用`min()`呢？因为只要有一个返回0，就说明有一个方向走出了边界，那该位置所在岛屿就不是封闭岛屿，即使其它三个方向都返回1.

聪明的你可能会问，既然有一个方向返回了0，那为什么还要继续走把其它方向走完呢？也就是说为什么不在`for`循环中加个判断呢
```cpp
for (int i = 0; i < 4; i++) {
    ret = min(ret, dfs(grid, r+vr[i], c+vc[i]));
    if (ret == 0) {
        return 0;
    }
}
```
其实这样是会出错的，因为当我们选择了一个陆地，我们就必须要把该陆地所在的岛屿上的所有位置遍历完，如果你没遍历完就结束，就相当于把一块岛屿分成了几个几块岛屿，如果原先的这块岛屿是封闭岛屿，你这样遍历就可能会得到几块封闭岛屿。得到的结果是大于答案的。

## BFS

- BFS是用队列来实现的，我们先将当前陆地的位置加入到队列中，然后取出当前位置，并将它标记为1，表示它已经遍历过了。
- 最后将它四个方向也为陆地的位置加入到队列中，一直循环，直到队列为空。

- 在循环的过程中我们需要判断是否走出了边界，如果走出了边界就说明该位置所在的岛屿不是封闭岛屿。

- BFS代码如下
```cpp
int bfs(vector<vector<int>>& grid, int r, int c) {
    int ret = 1;
    queue<vector<int>> q;
    q.push({r, c});
    while (!q.empty()) {
        vector<int> pos(q.front());
        q.pop();
        grid[pos[0]][pos[1]] = 1;
        int vr[] = {0, 1, 0, -1};
        int vc[] = {1, 0, -1, 0};
        for (int i = 0; i < 4; i++) {
            int curr = pos[0] + vr[i];
            int curc = pos[1] + vc[i];
        if (curr < 0 || curr >= grid.size() || curc < 0 || curc >= grid[0].size()) {
            ret = 0;
            continue;
        }
            if (grid[curr][curc] == 0) {
                q.push({curr, curc});
            }
        }
    }
    return ret;        
}
```

## 另一种思路

- 其实我们还可以直接从边界的陆地开始DFS或BFS遍历，只要边界陆地能遍历到的地方就不是封闭岛屿。
- 同时我们也要将遍历过得点置为1，表示该位置已经遍历过。
- 最后，里面为0的位置都是属于封闭岛屿的陆地了。

代码还是很好理解的
```cpp
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ret = 0;
        int ylen = grid.size();
        int xlen = grid[0].size();
        for (int i = 0; i < ylen; i++) {
            for (int j = 0; j < xlen; j++) {
                if (i == 0 || j == 0 || i == ylen-1 || j == xlen-1) {
                    bfs(j, i, grid);
                    //或者dfs(j, i, grid);
                }
            }
        }
        for (int i = 0; i < ylen; i++) {
            for (int j = 0; j < xlen; j++) {
                if (grid[i][j] == 0) {
                    ret++;
                    bfs(j, i, grid);
                    //或者dfs(j, i, grid);
                }
            }
        }
        return ret;
    }
    
    void dfs(int x, int y, vector<vector<int>>& grid) {
        int xlen = grid[0].size();
        int ylen = grid.size();
        if (x >= xlen || y >= ylen || x < 0 || y < 0 || grid[y][x] == 1) {
            return;
        }
        grid[y][x] = 1;
        int vx[] = {0, 1, 0, -1};
        int vy[] = {1, 0, -1, 0};
        for (int i = 0; i < 4; i++) {
            dfs(x+vx[i], y+vy[i], grid);
        }
    }
    
    void bfs(int x, int y, vector<vector<int>>& grid) {
        if (grid[y][x] == 1) {
            return;
        }
        int xlen = grid[0].size();
        int ylen = grid.size();
        queue<vector<int>> q;
        q.push({x, y});
        
        int vx[] = {0, 1, 0, -1};
        int vy[] = {1, 0, -1, 0};
        
        while (!q.empty()) {
            int curx = q.front()[0];
            int cury = q.front()[1];
            q.pop();
            grid[cury][curx] = 1;
            for (int i = 0; i < 4; i++) {
                int nextx = curx+vx[i];
                int nexty = cury+vy[i];
                if (nextx >= 0 && nextx < xlen && nexty >= 0 && nexty < ylen) {
                    if (grid[nexty][nextx] == 0) {
                        q.push({nextx, nexty});
                    }
                }
            }            
        }
    }
};
```

## 总结

这道题虽然不怎么难，但只要真正理解了这道题，其它DFS和BFS题也就大同小异了。

**[点我阅读原文](https://mp.weixin.qq.com/s/rQTiywWh4C9bAc3oYvRvrA)**


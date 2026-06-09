基本的BFS求解，关键的点在选择重复性校验的问题上，避免走回头路

有一个比较好的记录方式：两个点的移动轨迹 A->B作为重复性识别

76ms 30.2M
--- wangtao HW-2020/2/22

```
typedef struct LOCATION {
        int x;
        int y;
        LOCATION(int i, int j) : x(i), y(j) {}
} LOCATION;

class Solution {
public:
    /* 思路
    1、箱子初始位置和人初始位置入队列，队列中包含(箱子位置, 人位置, 箱子移动次数)
    2、出队列开始查找新一批入队列元素，要求
        > 箱子能向某个方向移动，基本条件
        > 人能到达箱子移动反方向的空地，DFS搜索结果
        > 入队列新的箱子位置和人的位置，箱子移动次数+1
        > 避免死循环，记录箱子移动到某个位置时的移动次数和当前位置为visited访问，只有操作不重复才能入队列
    3、出队列的时候查看箱子是否已到终点，到达的话结束
    */

    int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool movevalid(vector<vector<char>>& grid, int x, int y, int m, int n)
    {
        return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != '#';
    }

    bool peoplecanreachdfs(vector<vector<char>>& grid, vector<vector<int>>& visited, LOCATION src, LOCATION boxloc, LOCATION dst)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        if (src.x == dst.x && src.y == dst.y) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int nx = src.x + d[i][0];
            int ny = src.y + d[i][1];
            // 需要注意下，此时box的位置，人无法通过BOX
            if (nx == boxloc.x && ny == boxloc.y) continue;
            if (movevalid(grid, nx, ny, m, n) && visited[nx][ny] == 0) {
                visited[nx][ny] = 1;
                if (true == peoplecanreachdfs(grid, visited, LOCATION(nx, ny), boxloc, dst)) {
                    return true;
                }
            }
        }
        return false;
    }

    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        LOCATION people(0, 0);
        LOCATION box(0, 0);
        LOCATION target(0, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'S') {
                    people.x = i;
                    people.y = j;
                } else if (grid[i][j] == 'B') {
                    box.x = i;
                    box.y = j;
                } else if(grid[i][j] == 'T') {
                    target.x = i;
                    target.y = j;
                }
            }
        }
        set<pair<pair<int, int>, pair<int, int>>> visited;
        queue<pair<pair<LOCATION, LOCATION>, int>> qu;
        qu.push({{box, people}, 0});

        int ans = -1;
        while(!qu.empty()) {
            pair<pair<LOCATION, LOCATION>, int> cur = qu.front();
            qu.pop();
            LOCATION boxloc = cur.first.first;
            LOCATION peopleloc = cur.first.second;
            int step = cur.second;

            if (boxloc.x == target.x && boxloc.y == target.y) {
                ans = step;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int x = boxloc.x + d[i][0];
                int y = boxloc.y + d[i][1];

                // 箱子移动方向是否可行
                if (!movevalid(grid, x, y, m, n)) continue;
                // 反方向人能不能站住脚+人能不能到达
                int px = boxloc.x - d[i][0];
                int py = boxloc.y - d[i][1];
                if (!movevalid(grid, px, py, m, n)) continue;
                vector<vector<int>> peovisited(m, vector<int>(n, 0));
                peovisited[peopleloc.x][peopleloc.y] = 1;
                if (!peoplecanreachdfs(grid, peovisited, peopleloc, boxloc, LOCATION(px, py))) continue;
                // 人能到达，那就查看箱子移动到的位置是否重复
                if(visited.count({{boxloc.x, boxloc.y}, {x, y}}) == 0) {
                    visited.insert({{boxloc.x, boxloc.y}, {x, y}});
                    qu.push({{LOCATION(x, y), boxloc}, step + 1});
                }
            }
        }
        return ans;
    }
};
```

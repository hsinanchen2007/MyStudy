```cpp
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        struct T { int x, y; };
        using Area = vector<T>;
        
        const int M = grid.size(), N = grid[0].size();
        vector<vector<int>> visited(M, vector<int>(N, 0));
        
        const auto in_grid = [&](T p) { return p.x >= 0 && p.x < M && p.y >= 0 && p.y < N; };
        
        // 从 p 点开始扩展区域，访问的点存入 area 中
        const auto expand = [&](T p, Area& area) {
            while (in_grid(p) && visited[p.x][p.y] == 0) {
                visited[p.x][p.y] = 1;
                area.push_back(p);
                
                switch (grid[p.x][p.y]) {
                    case 1: p.y += 1; break;
                    case 2: p.y -= 1; break;
                    case 3: p.x += 1; break;
                    case 4: p.x -= 1; break;
                    default: break;
                }
            }
        };
        
        // 计算轮廓线
        const auto calcSide = [&](Area& cur, Area& side){
            for (auto p: cur) {
                const T neighbours[] = {
                    {p.x + 1, p.y}, 
                    {p.x - 1, p.y},
                    {p.x, p.y + 1},
                    {p.x, p.y - 1},
                };
                for (auto& n: neighbours) {
                    if (in_grid(n) && visited[n.x][n.y] == 0) {
                        side.push_back(n);
                    }
                }
            }
        };
        
        // 初始化：从起点开始构造一个初始区域
        Area cur, next;
        expand({0, 0}, cur);
        
        int term = 0;
        while (!cur.empty()) {
            // 检查是否已抵达终点
            for (auto& p: cur) {
                if (p.x == M - 1 && p.y == N - 1) {
                    return term;
                }
            }
            
            // 从当前区域计算邻接区域
            Area side;
            calcSide(cur, side);
            
            next.clear();
            for (auto p: side) {
                expand(p, next); // 从 side 开始扩展
            }
            
            // 轮数 + 1
            swap(cur, next);
            term++;
        }
        
        return -1;
    }
};
```
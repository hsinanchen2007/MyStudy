### 解题思路
BFS:学习BUF框架，参考
https://leetcode-cn.com/problems/rotting-oranges/solution/li-qing-si-lu-wei-shi-yao-yong-bfsyi-ji-ru-he-xie-/

### 代码

```cpp

struct Pos {
    Pos (int r, int c) : row(r), col(c) {}
    int row;
    int col;
};

class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return -1;
        }

        queue<Pos> rot_queue;
        int cnt = 0;
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == 2) {
                    rot_queue.push(Pos(r, c));
                } else if (grid[r][c] == 1) {
                    ++cnt;
                }
            }
        }

        if (cnt == 0) {
            return 0;
        }

        vector<vector<int>> visit(grid.size(), vector<int>(grid[0].size(), 0));
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int depth = 0;
        while (!rot_queue.empty()) {
            ++depth;

            int num = rot_queue.size();
            for (int i = 0; i < num; ++i) {
                Pos p = rot_queue.front();
                rot_queue.pop();

                for (int j = 0; j < 4; ++j) {
                    int tmpr = p.row + dr[j];
                    int tmpc = p.col + dc[j];

                    if (tmpr >= 0 && tmpr < grid.size() && tmpc >= 0 && tmpc < grid[0].size()) {
                        if (visit[tmpr][tmpc] == 0 && grid[tmpr][tmpc] == 1) {
                            visit[tmpr][tmpc] = 1;
                            grid[tmpr][tmpc] = 2;
                            rot_queue.push(Pos(tmpr, tmpc));
                            
                            --cnt;                            
                            if (cnt == 0) {
                                return depth;
                            }
                        }
                    }
                }

            }
        }

        return -1;
    }

};
```
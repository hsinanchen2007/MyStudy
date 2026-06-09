### 解题思路
BFS 从起点开始一圈一圈扫描。第N圈碰到结束点时，则N就是最短路径
提升效率关键点：
**放入buff中的元素需要设置为1，防止后续继续添加**

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> moves = {
        { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }, { 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1 }
    };
    bool inArea(int i, int j, vector<vector<int>> &grid)
    {
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid.size()) {
            return true;
        }

        return false;
    }

    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        deque<pair<int, int>> buff;
        int count = 0;
        if (!grid.empty() && grid[0][0] == 0) {
            buff.push_back(pair<int, int>(0, 0));
        } else {
            return -1;
        }

        int lastpoint = grid.size() - 1;

        while (!buff.empty()) {
            count++;
            int length = buff.size();
            for (int i = 0; i < length; i++) {
                int oldi = buff.front().first;
                int oldj = buff.front().second;

                if (oldi == lastpoint && oldj == lastpoint) {
                    return count;
                }
                for (auto move : moves) {
                    int newi = oldi + move[0];
                    int newj = oldj + move[1];
                    if (inArea(newi, newj, grid) && grid[newi][newj] != 1) {
                        buff.push_back(pair<int, int>(newi, newj));
                        //效率提升关键点
                        **grid[newi][newj] = 1;**
                    }
                }

                buff.pop_front();
            }
        }

        return -1;
    }
};
```
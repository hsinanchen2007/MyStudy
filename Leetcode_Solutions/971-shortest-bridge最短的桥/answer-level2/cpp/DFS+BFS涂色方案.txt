### 解题思路

思路：DFS+BFS涂色方案
1、题目给定的图中存在两个连通块，现在要求的是两个连通块的最短距离
2、为了区分两个连通块，将其中一个进行涂色，DFS遍历修改原数组中其中一个连通块的值
3、以其中一个连通块为基准，将坐标及初始设定step全部加入队列中，BFS遍历求解，在第一次遇到另一个连通块时退出

72ms 20.5M
--- wangtao HW-2020/3/8

### 代码

```cpp
class Solution {
public:
    int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    void dfs(vector<vector<int>>& A, int x, int y)
    {
        for (int i = 0; i < 4; i++) {
            int newx = x + d[i][0];
            int newy = y + d[i][1];

            if (newx >= 0 && newx < A.size() && newy >= 0 && newy < A[0].size() && A[newx][newy] == 1) {
                A[newx][newy] = 2;
                dfs(A, newx, newy);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& A) {
        int findflag = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                if (A[i][j] == 1) {
                    A[i][j] = 2;
                    dfs(A, i, j);
                    findflag = 1;
                    break;
                }
            }
            if (findflag == 1) {
                break;
            }
        }
        // 连通块已涂色，分为三块，0不连通，1和2代表两个连通块
        // 选定一个连通块的所有节点，把所有节点值为1的入队列，BFS遍历走到另一个连通块的最小路径长度
        int minVal = INT_MAX;
        queue<pair<pair<int, int>, int>> qu;
        map<pair<int, int>, int> visited;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                if (A[i][j] == 1) {
                    qu.push({{i, j}, 0});
                }
            }
        }       
        while (!qu.empty()) {
            pair<pair<int, int>, int> cur = qu.front();
            int x = cur.first.first;
            int y = cur.first.second;
            int step = cur.second;
            qu.pop();

            if (A[x][y] == 2) {
                minVal = min(minVal, step-1);
                break;
            }
            for (int k = 0; k < 4; k++) {
                int newx = x + d[k][0];
                int newy = y + d[k][1];
                if (newx >= 0 && newx < A.size() && newy >= 0 && newy < A[0].size() && 
                    A[newx][newy] != 1 && (visited.count({newx, newy}) == 0 || 
                    (visited.count({newx, newy}) != 0 && visited[{newx, newy}] > step + 1))) {
                    visited[{newx, newy}] = step + 1;
                    qu.push({{newx, newy}, step+1});
                }
            }
        }
        return minVal == INT_MAX ? -1 : minVal;
    }
};
```
* 思路就是通过BFS将所有可达的格子找到，如果包含最后一个格子，那么直接return true
* 代码中注释

```C++
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid);
};

// 方向数组
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

// 表示每个方向可行的组合，0123分别是上、右、下、左
// 这样省去在代码中过多的if-else判断
// 写这些组合的时候，忘记了1和2的特殊性，因为1和2可以自己联通自己，提交时候卡在[[1,1,1,3]]这种用例时候发现的
// 一定要仔细点
map<int,set<pair<int,int>>> avaliablePath = {
    {0, {{2,2},{2,3},{2,4},{5,2},{5,3},{5,4},{6,2},{6,3},{6,4}}},
    {1, {{1,1},{1,3},{1,5},{4,1},{4,3},{4,5},{6,1},{6,3},{6,5}}},
    {2, {{2,2},{2,5},{2,6},{3,2},{3,5},{3,6},{4,2},{4,5},{4,6}}},
    {3, {{1,1},{1,4},{1,6},{3,1},{3,4},{3,6},{5,1},{5,4},{5,6}}}
};

// 判断前一个节点和当前节点是否可以联通
bool canPass(vector<vector<int>> &grid, vector<vector<int>> &visited, int x, int y, int parent, int direction) {
    int m = grid.size(), n = grid[0].size();
    if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) return false;
    auto p = make_pair(parent, grid[x][y]);
    if (avaliablePath[direction].count(p))
        return true;
    return false;
}

bool Solution::hasValidPath(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int,int>> q;
    q.push({0,0});
    vector<vector<int>> visited(m, vector<int> (n, 0));
    visited[0][0] = 1;
    while (!q.empty()) {
        auto currnode = q.front(); q.pop();
        if (currnode.first == m - 1 && currnode.second == n - 1) return true;
        for (int i = 0; i < 4; i++) {
            int x = currnode.first + dx[i];
            int y = currnode.second + dy[i];
            if (canPass(grid, visited, x, y, grid[currnode.first][currnode.second], i)) {
                visited[x][y] = 1;
                q.push({x,y});
            }
        }
    }
    return false;
}
```
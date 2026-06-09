### 解题思路
![1.png](https://pic.leetcode-cn.com/68a174a44f4a09e4d28e0f153768234068eeac0c69ebf8e613848734aca5b8e1-1.png)
学习了喂你脚下有坑的思路，略有修改。思路就是采用0-1BFS，如果前进到下一个位置不需要代价，则插入到队首。如果前进到下一个位置需要代价，那么插入到队尾。这样就能保证整个队列是有序的。用一个最短路径数组维护位置的最短路径。

### 代码

```cpp
const int MAXN = 150;
int dist[MAXN][MAXN];
bool visited[MAXN][MAXN];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1 ,-1, 0, 0};

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        memset(dist, -1, sizeof(dist));
        memset(visited, false, sizeof(visited));
        int m = grid.size();
        int n = grid[0].size();
        deque<pair<int, int> > que;  // 双端队列
        dist[0][0] = 0;
        que.push_back({0, 0});
        
        while(!que.empty()) {
            pair<int, int> cur = que.front();
            que.pop_front();
            
            int x = cur.first;
            int y = cur.second;
            if(visited[x][y] == true) continue;
            visited[x][y] = true;
            
            for(int i = 0; i < 4; i++) {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if(tx < 0 || ty < 0 || tx >= m || ty >= n) continue;//越界，继续
                if(grid[x][y] == i + 1) {
                    if(dist[tx][ty] == -1)   //这里表示{tx, ty}没有访问过，那么就直接赋值
                        dist[tx][ty] = dist[x][y];
                    else
                        dist[tx][ty] = min(dist[tx][ty], dist[x][y]);  //如果访问过，那么要更新成最小值
                    que.push_front({tx, ty});  //插入到队首
                }
                else {
                    if(dist[tx][ty] == -1)
                        dist[tx][ty] = dist[x][y] + 1;
                    else
                        dist[tx][ty] = min(dist[tx][ty], dist[x][y] + 1);
                    que.push_back({tx, ty});  //插入到队尾
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};
```

方法二：思路一样，不过pair里面保存的是代价和位置对。这样就不需要用dist数组了，方法清晰。

### 代码

```cpp
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        deque<pair<int, int> > que;  //first表示代价，second表示坐标
        que.push_back({0, 0});
        while(!que.empty()) {
            pair<int, int> cur = que.front();
            que.pop_front();
            
            int x = cur.second / n;
            int y = cur.second % n;
            if(visited[x][y]) continue;
            visited[x][y] = true;
            
            if(x == m - 1 && y == n - 1)
                return cur.first;
            for(int i = 1; i <= 4; i++) {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if(tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
                if(grid[x][y] == i) {
                    que.push_front({cur.first, tx * n + ty});
                }
                else {
                    que.push_back({cur.first + 1, tx * n + ty});
                }
            }
        }
        
        return -1;
    }
};
```
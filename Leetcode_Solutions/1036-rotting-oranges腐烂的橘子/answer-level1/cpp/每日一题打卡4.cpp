### 解题思路
多源BFS，思路详见代码注释

### 代码

```cpp
class Solution {
private:
    int cnt = 0; //网格中剩余1的个数,初始化为0
    int dist[10][10]; //定义距离矩阵,记录橘子腐烂的时间步
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
public:
    //多源BFS,第一阶段先找到多源，第二阶段进行BFS
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int, int>> Q; //队列里存放坐标(x, y)
        memset(dist, -1, sizeof(dist)); //将dist指针指向的数组初始化为-1,初始时间步均为-1
        int m = grid.size(); //行数
        int n = grid[0].size(); //列数
        //第一阶段:寻找多源,并将一开始腐烂的橘子入队列,同时统计新鲜橘子数
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    dist[i][j] = 0; //初始时刻腐烂的橘子,对应的时间步为0
                    Q.push(make_pair(i, j));
                }
                else if(grid[i][j] == 1) {
                    cnt += 1; //在寻找多源的过程中,顺便统计新鲜橘子的总数
                }
            }
        }
        //第二阶段:BFS
        int ans = 0;
        while(!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();
            //int ans = 0; //循环里的变量在循环结束后都释放了?
            for(int i = 0; i < 4; i++) {
                int x = cur.first + dx[i], y = cur.second + dy[i]; //从当前节点向四个方向拓展
                if(x < 0 || x >= m || y < 0 || y >= n || (dist[x][y] != -1) || (grid[x][y] == 0))
                    continue; //如果遍历到的新节点 坐标越界||已经访问过(等价于腐烂的节点)||是空节点, 不再进行遍历
                //此时节点一定是新鲜节点
                dist[x][y] =  dist[cur.first][cur.second] + 1;
                Q.push(make_pair(x, y));
                cnt --;
                if(cnt == 0) {
                    //return dist[x][y];
                    ans = dist[x][y];
                    break;
                }
            }
        }
        return (cnt == 0) ? ans : -1;
    }
};
```
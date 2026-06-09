```c++ []
#include <queue>
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // 提取地图信息
        this->R = grid.size();
        this->C = grid[0].size();

        // 特殊情况处理
        if(grid[0][0] == 1)
            return -1;
        if(R == 1 && C == 1)
            return 1;
        if(grid[R-1][C-1] == 1)
            return -1;
        
        this->visited = vector<vector<bool>>(R, vector<bool>(C, false));
        this->dis = vector<vector<int>>(R, vector<int>(C, 0));
        // 最短路径求解，使用bfs算法, 建立辅助队列
        queue<int> q;
        dis[0][0] = 1;
        q.push(0 * C + 0);
        visited[0][0] = true;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            // 将一维坐标映射回二维坐标
            int cur_x = cur / C;
            int cur_y = cur % C;
            // 对八连通方向进行探测
            for(auto d: dirs){
                int new_x = cur_x + d[0];
                int new_y = cur_y + d[1];
                // 对可行点进行访问
                if(inArea(new_x, new_y) && !visited[new_x][new_y] && grid[new_x][new_y]==0){
                    visited[new_x][new_y] = true;
                    q.push(new_x*C + new_y);
                    dis[new_x][new_y] = dis[cur_x][cur_y] + 1;
                    // 如果已经到达右下角
                    if(new_x == R-1 && new_y == C-1)
                        return dis[new_x][new_y];
                }
            }
        }
        return -1;
        
    }

// 定义私有函数
private:
    // 判断当前位置是否合法
    bool inArea(int x, int y){
        return 0<=x && x<R && 0<=y && y<C;
    }

// 定义变量
private:
    // 八连通方向
    vector<vector<int>> dirs = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    // 行数
    int R;
    // 列数
    int C;
    // 访问数组
    vector<vector<bool>> visited;
    // 路径长度
    vector<vector<int>> dis;
};
```
```python []
from queue import Queue
class Solution:
    R, C = 0, 0
    dirs = [[-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1]]
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        # 提取地图信息
        self.R = grid.__len__()
        self.C = grid[0].__len__()

        # 判断图形的特殊情况
        if grid[0][0] == 1:
            return -1

        if self.R == 1 and self.C == 1:
            return 1

        if grid[self.R-1][self.C-1] == 1:
            return -1

        visited = [[False for _ in range(self.C)] for _ in range(self.R)]
        dist = [[0 for _ in range(self.C)] for _ in range(self.R)]

        # 最短路径问题, 使用bfs算法
        q = Queue()
        dist[0][0] = 1
        visited[0][0] = True
        q.put(0 * self.C + 0)
        while q.empty() is False:
            cur = q.get()
            cur_x = cur // self.C
            cur_y = cur % self.C

            for d in self.dirs:
                new_x = cur_x + d[0]
                new_y = cur_y + d[1]
                if self.inArea(new_x, new_y) and visited[new_x][new_y] is False and grid[new_x][new_y] == 0:
                    visited[new_x][new_y] = True
                    q.put(new_x * self.C + new_y)
                    dist[new_x][new_y] = dist[cur_x][cur_y] + 1
                    # 提前返回机制
                    if new_x == self.R-1 and new_y == self.C-1:
                        return dist[new_x][new_y]
        return -1

    def inArea(self, x:int, y:int) -> bool:
        return 0<= x and x < self.R and 0<= y and y< self.C
```
```java []
class Solution {
    // 设置八连通方向
    private int[][] dirs = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    private int[][] grid;
    private int[][] dis;
    private boolean[][] visited;
    private int R, C;
    public int shortestPathBinaryMatrix(int[][] grid) {
        // 当起始点为阻塞时, 最短路径不存在
        if(grid[0][0]==1)
            return -1;
        
        R = grid.length;
        C = grid[0].length;

        // 如果图形只有一格, 最短路径为0
        if(R == 1 && C == 1)
            return 1;
        visited = new boolean[R][C];
        dis = new int[R][C];
        // 记录路径长度
        dis[0][0] = 1;
        visited[0][0] = true;
        // bfs算的辅助队列, 多次在队首和队尾操作, 使用LinkedList实现
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0 * C + 0);
        // 根据bfs最短路径的性质, 使用bfs进行求解
        while(!queue.isEmpty()){
            int cur = queue.remove();
            int cur_x = cur/C;
            int cur_y = cur%C;
            // 对已经访问过的顶点进行八连通探测
            for(int[] d: dirs){
                int new_x = cur_x + d[0];
                int new_y = cur_y + d[1];
                if(inArea(new_x, new_y)&&!visited[new_x][new_y] && grid[new_x][new_y]==0){
                    visited[new_x][new_y]=true;
                    queue.add(new_x*C+new_y);
                    dis[new_x][new_y] = dis[cur_x][cur_y] + 1;
                    if(new_x == R-1 && new_y == C-1)
                        return dis[R-1][C-1]; 
                }
            }
        }
        return -1;
    }

    private boolean inArea(int x, int y){
        return 0<=x && x<R && 0<=y && y<C;
    }
}
```

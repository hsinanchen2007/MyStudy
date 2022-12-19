### 解题思路
1. 先考虑四周, 取出最小元素开始DFS, 更新规则$\max(0, node.h-heightMap[x][y])$

### 代码

```c++ []
struct Node{
    int x;
    int y;
    int height;
    bool operator< (const Node& node) const{
        return this->height < node.height;
    }

    bool operator> (const Node& node) const{
        return this->height >= node.height;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        R = heightMap.size();
        if(R == 0)
            return 0;
        C = heightMap[0].size();
        if(C == 0)
            return 0;
        
        // 最小堆优先队列
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        // 访问状态记录
        vis = vector<vector<bool>>(R, vector<bool>(C, false)); 

        // 先将四周Node压入队列
        for(int i=0; i<R; ++i){
            pq.push({i, 0, heightMap[i][0]});
            vis[i][0] = true;
            pq.push({i, C-1, heightMap[i][C-1]});
            vis[i][C-1] = true;
        }

        for(int j=0; j<C; ++j){
            pq.push({0, j, heightMap[0][j]});
            vis[0][j] = true;
            pq.push({R-1, j, heightMap[R-1][j]});
            vis[R-1][j] = true;
        }

        int res = 0;
        while(!pq.empty()){
            Node node = pq.top();
            pq.pop();
            for(auto &d: dirs){
                int nx = node.x+d[0];
                int ny = node.y+d[1];
                if(inArea(nx, ny) && !vis[nx][ny]){
                    vis[nx][ny] = true;
                    pq.push({nx, ny, max(node.height, heightMap[nx][ny])});
                    res += max(0, node.height-heightMap[nx][ny]);
                }
            }
        }

        return res;
    }

private:
    int R, C;
    vector<vector<bool>> vis;
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool inArea(int x, int y){
        return 0<=x && x<R && 0<=y && y<C;
    }
};
```
```java []
class Node{
    int x;
    int y;
    int h;
    Node(int x, int y, int h){
        this.x = x;
        this.y = y;
        this.h = h;
    }
}


class Solution {
    public int trapRainWater(int[][] heightMap) {
        R = heightMap.length;
        if(R == 0)
            return 0;
        C = heightMap[0].length;
        if(C == 0)
            return 0;
        vis = new boolean[R][C];
        // 最小堆优先队列
        PriorityQueue<Node> pq = new PriorityQueue<>((Node n1, Node n2)->{
            if(n1.h > n2.h)
                return 1;
            else if(n1.h == n2.h)
                return 0;
            else
                return -1;
        });
        // 将四周节点压入队列
        for(int i=0; i<R; ++i){
            pq.offer(new Node(i, 0, heightMap[i][0]));
            vis[i][0] = true;
            pq.offer(new Node(i, C-1, heightMap[i][C-1]));
            vis[i][C-1] = true;
        }
        for(int j=1; j<C-1; ++j){
            pq.offer(new Node(0, j, heightMap[0][j]));
            vis[0][j] = true;
            pq.offer(new Node(R-1, j, heightMap[R-1][j]));
            vis[R-1][j] = true;
        }

        int res = 0;
        while(!pq.isEmpty()){
            Node node = pq.poll();
            for(int []d: dirs){
                int nx = node.x+d[0];
                int ny = node.y+d[1];
                if(inArea(nx, ny) && !vis[nx][ny]){
                    vis[nx][ny] = true;
                    // 较高node.h值移动更新
                    pq.offer(new Node(nx, ny, Math.max(heightMap[nx][ny], node.h)));
                    res += Math.max(0, node.h-heightMap[nx][ny]);
                }
            }
        }

        return res;
    }

    private int R, C;
    private boolean [][]vis;
    private int [][]dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    private boolean inArea(int x, int y){
        return 0<=x && x<R && 0<=y && y<C;
    }
}
```
```python []
class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        from queue import PriorityQueue as PQ
        # 使用tuple代替类
        R = len(heightMap)
        if R == 0: return 0
        C = len(heightMap[0])
        if C == 0: return 0
        vis = [[False for _ in range(C)] for _ in range(R)]
        dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
        # 判断是否发生越界
        def inArea(x, y):
            return 0<=x and x<R and 0<=y and y<C
        pq = PQ()
        for i in range(R):
            pq.put((heightMap[i][0], (i, 0, heightMap[i][0])))
            vis[i][0] = True
            pq.put((heightMap[i][C-1], (i, C-1, heightMap[i][C-1])))
            vis[i][C-1] = True

        for j in range(C):
            pq.put((heightMap[0][j], (0, j, heightMap[0][j])))
            vis[0][j] = True
            pq.put((heightMap[R-1][j], (R-1, j, heightMap[R-1][j])))
            vis[R-1][j] = True

        res = 0

        while pq.qsize()>0:
            _, (x, y, h) = pq.get()
            for d in dirs:
                nx, ny = x+d[0], y+d[1]
                if inArea(nx, ny) and vis[nx][ny] is False:
                    vis[nx][ny] = True
                    pq.put((max(heightMap[nx][ny], h), (nx, ny, max(heightMap[nx][ny], h))))
                    res += max(0, h-heightMap[nx][ny])
        return res
```
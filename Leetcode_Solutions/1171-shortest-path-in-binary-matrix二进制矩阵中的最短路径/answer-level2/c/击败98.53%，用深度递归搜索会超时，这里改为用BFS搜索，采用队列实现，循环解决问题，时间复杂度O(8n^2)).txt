### 解题思路
采用广度搜索的思想，第一步到达的节点的路径即为最短路径

### 代码

```cpp
class Solution {
private:
    struct Node {
        int x;
        int y; 
        int step;
        Node(int i, int j, int s): x(i), y(j), step(s){}
    };
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n, i, j;
        queue<struct Node> q;
        
        n = grid.size();
        if(n == 0 || grid[0][0] || grid[n-1][n-1]) return -1;

        // 默认当前第一个节点已经访问
        grid[0][0] = 1;
        // 到达[0,0]路径长度初始化为 1 
        q.push(Node(0, 0, 1));
        
        while(!q.empty()) {
            Node node = q.front();
            q.pop();

            // 判断是否到达终点
            if(node.x == n-1 && node.y == n-1) return node.step;
            
            for(int dx = -1; dx <= 1; dx++) {
                for(int dy = -1; dy <= 1; dy++) {
                    i = node.x + dx;
                    j = node.y + dy;
                    // 如果当前待访问的节点无效，或者不可访问，即 grid[i][j] = 1
                    // 就直接跳过，只需要将满足条件的路径点入队列
                    if(i < 0 || j < 0 || i >= n || j >= n || grid[i][j])
                        continue;
                    // 当前节点入队，并且路径长度加1
                    // 广度搜索，第一个到达该点的路径即为最短路径
                    q.push( Node(i, j, node.step + 1) );
                    // 标记为已访问
                    grid[i][j] = 1;
                }
            }
        }
        
        return -1;
    }

};
```
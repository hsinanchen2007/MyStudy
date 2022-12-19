
### 解题思路

木桶原理：木桶能盛多少水取决于最短的那一块木板

- 用优先队列维护木桶的外围边界
- 取最短的一块，向内找与他相邻的且未被访问的最短的那一块inner，如果inner更短，inner位置能保存的水就是差值
- 不断缩小范围，直到所有木板都遍历完毕

```cpp
Q<x,y,h>：优先级队列；
将地图的四周作为第一个边界，存入Q；
总储水量 = 0;
while(Q不空){
    <x,y,h> = Q弹出堆顶;
    for(<nx,ny> in <x,y>的上下左右){
        if(<nx,ny> 在图上 且 在边界内部){
            总储水量 += max(0, h - <nx,ny>的高度);
            新边界位置<nx,ny, max(h,<nx,ny>的高度)>入Q;
        }
    }
}
```

### 代码实现

```cpp
struct Node{
    int x , y , h;
    Node(int _x, int _y, int _h): x(_x), y(_y), h(_h){};
    bool friend operator< (const Node &n1, const Node &n2){
        return n1.h > n2.h;
    }
};
class Solution {
public:
    int dirR[4] = {-1, 0, 1, 0};
    int dirC[4] = {0, 1, 0, -1};
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size() == 0 || heightMap[0].size() ==0) return 0;
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<Node> q; // 优先队列维护最外层边界
        // 是否访问到；是否在围墙外层
        vector<vector<int>> visited(m , vector<int>(n, 0));
        // 边界入堆
        for (int i =0; i< n; i++){
            q.push({0, i, heightMap[0][i]});
            q.push({m-1, i, heightMap[m-1][i]});
            visited[0][i] = visited[m-1][i] = 1;
        }
        for (int i = 1; i< m -1; i++){
            q.push({i, 0, heightMap[i][0]});
            q.push({i, n -1, heightMap[i][n-1]});
            visited[i][0] = visited[i][n-1] = 1;
        }
        int ans = 0;

        while (!q.empty()){
            auto top = q.top();
            q.pop();
            for (int d = 0; d< 4; d++){
                int r = dirR[d] + top.x;
                int c = dirC[d] + top.y;
                if (r <0 || r >=m || c < 0|| c >= n) continue;
                if (visited[r][c]) continue;
                visited[r][c] = 1;
                if (heightMap[r][c] < top.h){
                    ans += (top.h - heightMap[r][c]);
                }
                q.push({r, c, max(top.h, heightMap[r][c])});
            }
        }
        return ans;
    }
};
```

[从零开始学算法](https://muyids.github.io/simple-algorithm/)
### 解题思路

松弛 K+1 轮。

### 代码

```cpp
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dis(n, INT_MAX);
        dis[src] = 0;
        for(int i=1; i<=K+1; i++) {
            // flight 的顺序并不是按照节点顺序枚举，需要保存上一轮的状态数组
            vector<int> dis1 = dis;
            for(auto& flight: flights) {
                int u = flight[0];
                int v = flight[1];
                int w = flight[2];
                if(dis[u] != INT_MAX && dis1[v] > dis[u] + w) {
                    dis1[v] = dis[u] + w;
                }
            }
            dis.swap(dis1);
        }

        return dis[dst] == INT_MAX ? -1 : dis[dst];
    }
};
```
### 解题思路
使用Floyd算法算出每个节点间的最小距离后。然后遍历每个节点到其他节点的距离，如果小于distanceThreshold，则加入该城市的组数。最后看哪个城市的数组长度最小。相同的长度的时候取城市索引大的。

### 代码

```cpp
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist = vector<vector<int>>(n, vector<int>(n, 1e5));
        for (int i=0; i<n; i++) {
            dist[i][i] = 0;
        }
        for (auto v : edges) {
            dist[v[0]][v[1]] = v[2];
            dist[v[1]][v[0]] = v[2];
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                for (int k=0; k<n; k++) {
                    dist[j][k] = min(dist[j][i] + dist[i][k], dist[j][k]);
                }
            }
        }
        vector<int> r = vector<int>(n, 0);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if(i != j && dist[i][j] <= distanceThreshold) {
                    r[i]++;
                }
            }
        }
        int res = 0, count = INT_MAX;
        for (int i=0; i<n; i++) {
            if(r[i] <= count) {
                res = i;
                count = r[i];
            }
        }
        return res;
    }
};
```
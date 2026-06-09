### 解题思路
先回答怎么计算问题:
1. 至少需要n-1条网线才能连通所有计算机
2. 如果能连通的电脑群当做一个岛的话，我们需要计算有多少座岛。然后需要拆(岛数-1)条线来连通所有岛。

计算岛数方法:
1. 建建立计算机间连接关系(link_map)
2. 从第一台计算机开始，计算计算机群(岛)，计算过的都打个标记(mark)

### 代码

```cpp
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < (n-1)) {
            return -1;
        }

        unordered_map<int, unordered_set<int>> link_map;
        for (auto &conn : connections) {
            link_map[conn[0]].emplace(conn[1]);
            link_map[conn[1]].emplace(conn[0]);
        }

        vector<int> mark(n, 0);
        int num = 0;
        for (int i = 0; i < n; ++i) {
            if (mark[i]) continue;
            num++;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int index = q.front();
                q.pop();
                if (link_map.count(index) == 0) {
                    continue;
                }
                for (auto mi : link_map[index]) {
                    if (mark[mi]) continue;
                    q.push(mi);
                    mark[mi] = 1;
                }
            }
        }

        return num-1;
    }
};
```
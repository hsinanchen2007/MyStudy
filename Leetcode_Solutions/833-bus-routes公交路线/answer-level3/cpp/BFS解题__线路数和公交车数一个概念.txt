### 解题思路

思路：最少类问题，首先想到的是BFS，贪心也有可能，这题的话应该还算是比较典型的BFS吧
1、题目告诉了我们每一条公交路线上面有那些站点，其实这里每一条路线也就是一辆公交车，环形的线路
2、可以通过简单转换知道每一个站点有哪些线路经过，那么就可以从给定的S站点开始遍历线路，线路和当前已切换线路条数入队列
3、遍历每一条线路时，查看该线路上的是否有T，有的话可以直接结束，否则将线路加入的队列中，同时增加切换次数
4、线路的加入过滤，识别该线路是否已经访问过，避免重复计算
5、有个点需要注意下，unordered_map<int, set<int>>，每个站点加入的线路其实在表里应该是唯一的，一开始没注意，用了vector，最后一个用例超时

132ms 48.4M
--- wangtao HW-2020/3/1

### 代码

```cpp
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int, set<int>> station;

        // 人就在站点的时候，不需要坐车的
        if (S == T) return 0;
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                station[routes[i][j]].insert(i);
            }
        }
        vector<int> visited(routes.size(), 0);
        queue<pair<int, int>> qu;
        // S所在的线路先入队列
        for (auto c : station[S]) {
            qu.push({c, 1});
            visited[c] = 1;
        }
        int ans = -1;
        while(!qu.empty()) {
            pair<int, int> curline = qu.front();
            qu.pop();
            int lino = curline.first;
            int step = curline.second;

            for (int s = 0; s < routes[lino].size(); s++) {
                if (routes[lino][s] == T) {
                    ans = step;
                    break;
                }
                for (auto c : station[routes[lino][s]]) {
                    if (visited[c] == 0) {
                        visited[c] = 1;
                        qu.push({c, step + 1});
                    }
                }
            }
            if (ans != -1) { break; }
        }
        return ans;
    }
};
```
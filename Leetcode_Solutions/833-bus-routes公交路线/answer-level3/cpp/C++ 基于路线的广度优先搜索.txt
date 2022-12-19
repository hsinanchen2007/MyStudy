思路直观，见代码注释：
```
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;
        int N = routes.size();
        map<int, set<int> > m; // 存储车站能通到哪些路线
        for (int i = 0; i < N; ++i) {
            for (auto j : routes[i]) {
                m[j].insert(i);
            }
        }
        vector<bool> visited(N, false); // 哪些路线被遍历过了
        queue<int> q; // 存储已经遍历过的路线
        for (auto x : m[S]) {
            q.push(x);
            visited[x] = true;
        }
        int step = 0;
        while (!q.empty()) {
            ++step;
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                int t = q.front();
                q.pop();
                for (auto j : routes[t]) {
                    if (j == T) return step;
                    for (auto x : m[j]) {
                        if (!visited[x]) {
                            q.push(x);
                            visited[x] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};
```

![image.png](https://pic.leetcode-cn.com/adb8976df61c63e2c821a325200820302e793a6cc0c0b8db75281c2f7184248e-image.png)

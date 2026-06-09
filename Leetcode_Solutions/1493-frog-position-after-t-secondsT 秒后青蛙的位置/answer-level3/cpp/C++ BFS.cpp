## 代码
```cpp
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> mm(n + 1); // 记录和当前节点相邻的点
        vector<int> ret(n + 1, 0); // 记录当前节点到达的概率(跳到下一层需要标记为访问过且失效)
        for (const auto &edge : edges) {
            const auto a = edge[0];
            const auto b = edge[1];
            mm[a].push_back(b);
            mm[b].push_back(a);
        }
        ret[1] = 1;
        queue<int> qq;
        queue<int> times;
        qq.push(1);
        times.push(0);
        while (!qq.empty()) {
            auto cur = qq.front();
            auto time = times.front();
            time++;
            qq.pop();
            times.pop();
            const auto &mc = mm[cur];
            int child = 0;
            for (auto cc : mc) {
                if (!ret[cc]) {
                    child++;
                }
            }
            int tt = ret[cur] * child; // 计算当前节点每个子节点的到达概率
            for (auto cc : mc) {
                if (!ret[cc]) {
                    if (time < t) { // 未达目标步数，继续处理
                        ret[cc] = tt;
                        qq.push(cc);
                        times.push(time);
                    } else if (time == t) { // 正好到达了目标步数，只记录，终止处理
                        ret[cc] = tt;
                    }
                    
                }
            }
            if (tt) ret[cur] = -1; // 青蛙已经跳过下个节点，当前节点不可再次到达
        }
        return ret[target] > 0 ? ((double)1 / ret[target]) : 0;
    }
};
```
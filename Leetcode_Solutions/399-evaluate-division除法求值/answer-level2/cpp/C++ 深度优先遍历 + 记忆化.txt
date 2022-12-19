这里通过深度优先搜索把所有可以计算的字符串对都进行了计算，之后查询只需要直接取值就行了
```
class Solution {
public:
    vector<vector<int> > graph;
    vector<vector<double> > memo;
    vector<bool> visited;
    map<string, int> m;
    int N;
    void init(const vector<vector<string>>& equations, const vector<double>& values) {
        graph.clear();
        memo.clear();
        visited.clear();
        m.clear();
        int E = values.size();
        for (int i = 0; i < E; ++i) {
            if (m.count(equations[i][0]) == 0) m[equations[i][0]] = m.size();
            if (m.count(equations[i][1]) == 0) m[equations[i][1]] = m.size();
        }
        N = m.size();
        graph.resize(N);
        visited.resize(N);
        memo = vector<vector<double> >(N, vector<double>(N, -1.0));
        for (int i = 0; i < E; ++i) {
            int s = m[equations[i][0]];
            int t = m[equations[i][1]];
            double w = values[i];
            graph[s].push_back(t);
            graph[t].push_back(s);
            memo[s][t] = w;
            memo[t][s] = 1 / w;
            memo[s][s] = 1.0;
            memo[t][t] = 1.0;
        }
    }

    vector<int> dfs(int i) {
        vector<int> res{i};
        visited[i] = true;
        vector<vector<int> > groups;
        for (auto j : graph[i]) {
            if (!visited[j]) {
                auto nodes = dfs(j);
                for (auto x : nodes) {
                    if (memo[i][x] < 0) memo[i][x] = memo[i][j] * memo[j][x];
                    if (memo[x][i] < 0) memo[x][i] = 1 / memo[i][x];
                    res.push_back(x);
                }
                groups.push_back(nodes);
            }
        }
        int n = groups.size();
        for (int k1 = 0; k1 < n; ++k1) {
            for (int k2 = k1 + 1; k2 < n; ++k2) {
                for (auto s : groups[k1]) {
                    for (auto t : groups[k2]) {
                        if (memo[s][t] < 0) memo[s][t] = memo[s][i] * memo[i][t];
                        if (memo[t][s] < 0) memo[t][s] = 1 / memo[s][t];
                    }
                }
            }
        }
        return res;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        init(equations, values);
        for (int i = 0; i < N; ++i) {
            if (!visited[i]) dfs(i);
        }
        vector<double> res;
        for (auto& q : queries) {
            if (m.count(q[0]) && m.count(q[1])) {
                res.push_back(memo[m[q[0]]][m[q[1]]]);
            } else {
                res.push_back(-1.0);
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/4c55a3ef2a62907ace017cc77373a1e87212571a9f8ccde1935e0147843f27ce-image.png)

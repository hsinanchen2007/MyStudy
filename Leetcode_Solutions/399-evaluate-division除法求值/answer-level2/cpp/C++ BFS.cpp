简简单单bfs，注释详细代码整洁
```
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int M = equations.size(); // 一共有多少个除法式
        int N = 0; // 即将存储变量个数
        map<string, int> umap; // 标记变量是否出现过
        vector<double> res; // 结果
        for (int i = 0; i < M; i++) {
            // 需要将每个变量表示为数字序号，方便以后构建邻接矩阵
            string s0 = equations[i][0]; // 分子
            string s1 = equations[i][1]; // 分母
            if (umap.count(s0) == 0) { // 变量首次出现
                umap[s0] = N++; // 为该变量生成序号
            }
            if (umap.count(s1) == 0) {
                umap[s1] = N++;
            }
        }
        vector<vector<double>> adj(N, vector<double> (N, 0.0)); // N * N 邻接矩阵
        // 邻接矩阵初始化：
        for (int i = 0 ; i < M; i++) {
            // 对于"a"来说，如果存在"a/b"的表达式，则将adj[a, b]置为表达式的值，同时将adj[b, a]置为倒数
            // 需要找到string对应的序号
            string s0 = equations[i][0];
            string s1 = equations[i][1];
            int v = umap[s0];
            int w = umap[s1];
            adj[v][w] = values[i];
            adj[w][v] = double (1.0 / values[i]);
        }
        // 处理问题方程式：
        // 需要首先判断问题里的变量是否存在
        for (int i = 0; i < queries.size(); i++) {
            string s0 = queries[i][0];
            string s1 = queries[i][1];
            if (umap.count(s0) == 0 || umap.count(s1) == 0) {
                res.push_back(-1.0); // 如果变量不存在，则该表达式值为-1.0
                continue;
            }
            int v = umap[s0];
            int w = umap[s1];
            res.push_back(bfs(v, w, adj));
        }
        return res;
    }

    double bfs(int v, int w, vector<vector<double>>& adj) {
        if (adj.size() == 0) return -1.0;
        int N = adj[0].size();
        queue<pair<int, double>> q; // bfs 队列，用来记录遇到的结点和当前的乘法值
        map<int, int> umap; // 用来记录当前结点是否经过
        umap[v] = 1;
        if (adj[v][w] != 0.0) {
            return adj[v][w]; // 如果有已知的除法式的值，就直接返回
        }
        for (int i = 0; i < N; i++) {
            if (adj[v][i] != 0.0 && umap.count(i) == 0) { // 遇到一个没有经过且可以到达的结点
                q.push(make_pair(i, adj[v][i]));
                umap[i] = 1;
            }
        }
        while (!q.empty()) {
            int node = q.front().first;
            double last = q.front().second;
            q.pop();
            if (adj[node][w] != 0.0) {
                return last * adj[node][w];
            }
            for (int i = 0; i < N; i++) {
                if (adj[node][i] != 0.0 && umap.count(i) == 0) {
                    q.push(make_pair(i, last * adj[node][i]));
                    umap[i] = 1;
                }
            }
        }
        return -1.0;
    }
};
```

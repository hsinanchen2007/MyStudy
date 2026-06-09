![WechatIMG37.png](https://pic.leetcode-cn.com/9d7925d989623b2c29187f3507e11e8634d13acbcc1d8015ceb5ece2d39b2fea-WechatIMG37.png)

![BCC.jpeg](https://pic.leetcode-cn.com/b61ec7bede53f13faab50c258e26a8e373696d62626f2c74de8fe20a366d2555-BCC.jpeg)

我们考虑 c 的两颗子树

观察D所在的子树 其内部的某个节点 可以访问到 C 或者 C的祖先 A 那么 将 CD 断开 并不影响整个图的连通性
在观察E所在的子树 由于其内部的任何一个节点 都无法访问到 C的祖先 和 C本身 那么 CE 断开 E所在的子树 必然脱离整体 

```c++
vector<vector<int>> Graph;
vector<int> visited;   // 标记一个节点是否已经被访问
vector<int> visitTime; // 节点的访问时间， 时间越小代表访问越早
vector<int> Highestparent; // 节点可以访问到 最早 祖先
vector<vector<int>> ans;

int dfs(int node, int parent, int &clock) {
    visited[node] = 1;

    // 设置 节点的访问时间 并初始化该节点能访问到的最早祖先为该节点自己
    visitTime[node] = Highestparent[node] = clock; 

    for (int i = 0; i < Graph[node].size(); ++i) {
        if (Graph[node][i] != parent) { // 确保 dfs 是往更深处查询

            if (visited[Graph[node][i]] == 0) {  // 该节点还问被访问

                // node的子节点能访问到的最早祖先, hp越小 表示 越早
                int hp = dfs(Graph[node][i], node, ++clock); 

                // 若该最早祖先 比 node 访问的还要早 则更新node所能访问到的最早祖先 
                // 举个例子：比如 0 -> 1 -> 2 -> 0 显然 2 可以访问到 0, 由于 2 又是 1 的子节点 则 1 定能访问到 0
                Highestparent[node] = min(Highestparent[node], hp); 

                // 如果子节点 所能访问到的最早祖先 不早于 node 那么 node 与 该子节点的边 必然是关键路径
                if (hp > visitTime[node]) 
                    ans.push_back({node, Graph[node][i]});

            } else // 该节点已经访问过 直接更新
                Highestparent[node] = min(Highestparent[node], Highestparent[Graph[node][i]]);
        }
    }

    return Highestparent[node];
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections) {
    Graph = vector<vector<int>>(n);
    visited = vector<int>(n, 0);
    visitTime = vector<int>(n, 0);
    Highestparent = vector<int>(n, 0);
    ans = vector<vector<int>>();

    for (int i = 0; i < connections.size(); ++i) {
        Graph[connections[i][0]].push_back(connections[i][1]);
        Graph[connections[i][1]].push_back(connections[i][0]);
    }

    int clock = 0;
    dfs(0, -1, clock);
    return ans;
}
```
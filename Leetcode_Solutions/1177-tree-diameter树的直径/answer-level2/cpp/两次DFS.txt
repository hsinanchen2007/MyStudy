两次DFS.

第一次先以任一点为根， DFS后记录下距离。找到其中最长的点为第二次的根（如果有多个任意选一个）。

第二次以第一次DFS后得出的点为根， DFS仍然记录距离。 这里最长的距离就是直径。

代码如下。

```
class Solution {
public:

    static const int maxn = 10002;

    int dist[maxn], vis[maxn];
    vector<int> g[maxn];

    void DFS(int i){
        vis[i] = 1;
        for(unsigned int k = 0; k < g[i].size(); k++){
            int j = g[i][k];
            if(!vis[j]){
                dist[j] = dist[i] + 1;
                DFS(j);
            }
        }
    }

    int treeDiameter(vector<vector<int>>& edges) {
        int m = edges.size(), n = m + 1;

        for(int i = 0; i < m; i++){
            int u = edges[i][0], v = edges[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int root = 0;
        DFS(root);

        for(int i = 0; i < n; i++){
            if(dist[i] > dist[root])root = i;
        }

        memset(vis, 0, sizeof(vis));

        dist[root] = 0;
        DFS(root);

        for(int i = 0; i < n; i++){
            if(dist[i] > dist[root])root = i;
        }

        return dist[root];
    }
};
```

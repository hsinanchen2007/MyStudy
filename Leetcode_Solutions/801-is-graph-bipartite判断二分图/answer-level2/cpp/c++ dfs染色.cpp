### 解题思路
dfs染色。没有访问的初始化为-1，然后访问的时候，将它染成0或者1，遍历它相连的节点，将它的相连的节点染成不同的颜色。如果dfs的时候碰到了和该染的颜色不一样的已经染色节点，说明就不能二分图了。

### 代码

```cpp
class Solution {
public:
    bool isBipartiteDFS(vector<vector<int>>& graph, vector<int>& visited, int cur, int color) {
        if (visited[cur] != -1 && visited[cur] != color) {
            return false;
        }
        visited[cur] = color;
        for (auto i : graph[cur]) {
            if (visited[i] == visited[cur]) { //子节点的颜色和自己相同，说明已经不能二分图了
                return false;
            } else if (visited[i] == -1) {
                if (!isBipartiteDFS(graph, visited, i, (color + 1)%2)) { // 这里取不同的颜色
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited = vector<int>(graph.size(), -1);
        for (int i=0; i<graph.size(); i++) {
            if(visited[i] == -1) { //对仍没有染色的节点进行染色，这里是可以随便取初始的染色值的，因为如果之前的遍历都没有将这个节点染色，那么这个节点肯定是在另外的联通图里。
                if (!isBipartiteDFS(graph, visited, i, 0))
                    return false;
            }
        }
        return true;
    }
};
```
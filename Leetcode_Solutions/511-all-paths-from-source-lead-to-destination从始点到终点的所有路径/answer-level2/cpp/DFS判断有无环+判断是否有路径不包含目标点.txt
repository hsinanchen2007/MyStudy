### 解题思路
看了题解才做对，但是只能超过少部分用户
判断环：利用visit数组标记搜索过的点
判断路径：到叶子节点时候判断一下是否相同。
注意：只要是非叶子节点的位置的遇到了目标点，那要么后面的节点无法访问到目标点，要么就形成了环，因此都是错的，可以提前结束。
### 代码

```cpp
class Solution {
public:
    vector<int> graph[10010];
    bool visit[10010];
    
    
    bool dfs(int s, int d){
        if(s == d) return true;
        if(!graph[s].size()&&s!=d) return false;
        for(int node:graph[s]){
            if(visit[node]) return false;
            visit[node] = true;
            if(!dfs(node, d)) return false;
            visit[node] = false;
        }
        return true;        
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        
        memset(visit, false, sizeof(visit));
        for(auto edge:edges){
            graph[edge[0]].push_back(edge[1]);
        }
        return dfs (source, destination);
    }
};
```
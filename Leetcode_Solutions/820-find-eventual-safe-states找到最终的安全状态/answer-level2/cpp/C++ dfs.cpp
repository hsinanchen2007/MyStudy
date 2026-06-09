### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        if(graph.empty()) return vector<int>{};
        // dfs
        int n = graph.size();
        // 0未访问
        // 1由本次发起dfs的结点访问过，说明有环，在该环上的所有顶点都是不安全的
        // 2表示非本轮dfs访问的结点，安全
        vector<int>color(n,0);
        vector<int>ans;
        for(int i=0;i<n;++i)
        {
            if(dfs(i,graph,color))
                ans.emplace_back(i);
        }
        return ans;
    }
    bool dfs(int i,vector<vector<int>>& graph,vector<int>& color)
    {
        if(color[i]==1) return false;
        if(color[i]==2) return true;
        
        color[i] = 1;
        for(int j=0;j<graph[i].size();++j)
        {
            if(!dfs(graph[i][j],graph,color)) return false;
        }
        color[i] = 2;
        return true;
    }
};
```
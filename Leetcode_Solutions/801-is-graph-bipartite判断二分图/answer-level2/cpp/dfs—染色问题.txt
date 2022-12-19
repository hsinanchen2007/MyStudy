### 解题思路
经典的染色问题，使用dfs模板

### 代码

```cpp
class Solution {
public:
    vector<int> col;
    bool dfs(int i,int k,vector<vector<int>>& graph){
        col[i]=k;
        for(int j=0;j<graph[i].size();j++)
            if(col[graph[i][j]]==col[i])
                return false;
            else
                if(col[graph[i][j]]==-1&&dfs(graph[i][j],1-k,graph)==false)
                    return false;
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        for(int i=0;i<graph.size();i++)
            col.push_back(-1);
        for(int i=0;i<graph.size();i++)
            if(col[i]==-1&&dfs(i,0,graph)==false)
                return false;
        return true;
    }
};
```
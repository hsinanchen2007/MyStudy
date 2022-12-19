### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    //dfs
    bool flag;
    vector<int> visited;
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<vector<int>> G(n);
        visited = vector<int>(n,0);
        flag = false;//初始状态
        for(int i=0;i<graph.size();++i){ //建图
            G[graph[i][0]].push_back(graph[i][1]);
        }
        return dfs(G,start,target);
    }
    bool dfs(vector<vector<int>>& G,int v,int target){
        if(flag==true) return true;
        if(v==target){
            flag = true;
            return true;
        }
        visited[v] = 1;//置访问标记
        for(auto j:G[v]){ //所有邻接点
            if(visited[j]==0) //未被访问过
                dfs(G,j,target);
        }
        return flag;
    }
};
```
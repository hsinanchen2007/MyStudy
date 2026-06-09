### 解题思路
bfs 逐层染色 全遍历完没有跳出即返回true
注意 图是不联通的 有多个连通子图 这里有点坑  这个点我老半天才发现  

### 代码

```cpp
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(),f = 1,j = 0;
        vector<int>  vis(n,0);
        queue<int> que;
        bool ot = true;
       while(ot)
        {
            for(int i=0;i<n;i++){
            if(vis[i]==0&&graph[i].size()!=0){
             for(int j=0;j<graph[i].size();j++){
                    que.push(graph[i][j]);
                }
             vis[i] = f;
             ot = true;
             break;
            }
            ot = false;
        }
        
        while(!que.empty()){
            int size = que.size();
            for(int i=0;i<size;i++){
                int q = que.front();
                que.pop();
                if(vis[q]==f)
                return false;
                vis[q] = -f;
                for(int i:graph[q]){
                     if(vis[i]==-f)
                        return false;
                        if(vis[i]==0)
                        {
                            que.push(i);
                            vis[i] = f;
                        }
                }

            }
            f = -f;
        }
        }
        return true;
    }
        
};
```
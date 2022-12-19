1. 需要去掉重复的氛围两种情况：一是该图存在环，二是该图存在度为2的节点。
2. 首先检查是否存在入度为2的节点，找到连接度为2的节点的两条边，分别去掉一条边判断剩余的边组成的图是否有环。
   为什么不直接返回索引排序较大的边呢，因为存在以下类似的情况，比如：
    1->2->3->1  4->1 
    在这种情况下节点1的入度为2，分别存在两条可能需要去掉的边[3,1]与[4,1]，如果去掉[4,1],该图还是存在环，采用并查      集来判断该图是否存在环即可。
3. 如果该图不存在度为2的节点，则检查该图是否存在环，每加入一条边，用并查集检查该图是否存在环即可，或者用dfs或者BFS检查是否存在环。
```
class Solution {
public:
    int find(vector<int> & f,int x){
        while(x != f[x]){
            x = f[x];
        }
        return x;
    }
    
    bool uni(vector<int> & f,int x,int y){
        int x1 = find(f,x);
        int y1 = find(f,y);
        f[y1] = x1;
        return true;
    }
    
    bool checkRecyle(vector<vector<int>> & edges, int except){
        int n = edges.size();
        vector<int> f(n+1,0);
        
        for(int i = 1;i <= n; ++i){
            f[i] = i;
        }
                
        for(int i = 0;i < n; ++i){
            if(i == except){
                continue;
            }
            
            int x1 = find(f,edges[i][0]);
            int x2 = find(f,edges[i][1]);
            if(x1 == x2){
                return true;
            }
            f[x2] = x1;
        }
        return false;
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> indegree(n,vector<int>());
        vector<int> f(n+1,0);
        
        for(int i = 0;i < n; ++i){
            indegree[edges[i][1]-1].push_back(i);
            f[i+1] = i+1;
        }
        
        /*check two degree*/
        for(int i = 0;i < n; ++i){
            if(indegree[i].size() > 1){
                for(int j = indegree[i].size()-1; j >= 0; --j){
                    if(!checkRecyle(edges,indegree[i][j])){
                        return edges[indegree[i][j]];
                    }
                }
            }
        }
        
        /*check one degree*/
        for(auto e : edges){
            int x1 = find(f,e[0]);
            int x2 = find(f,e[1]);
            if(x1 == x2){
                return e;
            }
            f[x2] = x1;
        }
        
        return edges[0];
    }
};
```

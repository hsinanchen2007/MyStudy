```
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n,vector<int>());
        vector<int> degree(n,0);
        vector<int> ans;
        queue<int> qu;
              
        for(auto e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        
        if(n == 1){
            ans.push_back(0);
            return ans;
        }
        
        for(int i = 0; i < n; ++i){
            if(degree[i] == 1){
                qu.push(i);
                degree[i]--;
            }
        }
        
        int rest = n;
        while(!qu.empty()){
            if(rest == 1 || rest == 2){
                while(!qu.empty()){
                    ans.push_back(qu.front());
                    qu.pop();
                }
            }
            
            int level = qu.size();
            rest -= level;
            for(int i = 0;i < level; ++i){
                int curr = qu.front();
                qu.pop();
                    
                for(auto & v : graph[curr]){
                    if(degree[v] > 0){
                        degree[v]--;
                    }
                    if(degree[v] == 1){
                        qu.push(v);
                    }
                }
            }
        }
        
        return ans;
    }
};
```
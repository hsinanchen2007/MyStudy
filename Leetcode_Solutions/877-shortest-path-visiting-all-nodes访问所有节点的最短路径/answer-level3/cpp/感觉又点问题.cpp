```
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int r = graph.size();
        int mask = (1<<r)-1;
        int res = 0;
        vector<vector<bool>> visit(r,vector<bool>(mask,false));
        queue<pair<int,int>> qu;
        
        /*intial*/
        for(int i = 0;i < r; ++i){
            qu.push(make_pair(i,1<<i));
            visit[i][1<<i] = true;
        }
        
        while(!qu.empty()){
            int mx = qu.size();  
            
            for(int i = 0;i < mx; ++i){
                int curr = qu.front().first;
                int currState = qu.front().second;
                qu.pop();
                if(currState == mask){
                    return res;
                }
                
                for(int j = 0;j < graph[curr].size(); ++j){
                    int next = graph[curr][j];
                    int nextState = currState|(1<<next);
                    if(!visit[next][nextState]){
                        visit[next][nextState] = true;
                        qu.push(make_pair(next,nextState));
                    }
                }
            }
            res++;
        }
        
        return res;
    }
};
```
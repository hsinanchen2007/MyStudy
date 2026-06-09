```

class Solution {
public:
    int visit[55][55][55];
    int dp[55][55][55];
    
    int helper(int cat, int mouse, vector<vector<int>> & graph,int t) {
        int ans = -2;
        
       if(t >= graph.size()+1){
           visit[cat][mouse][t] = 1;
           return 0;
       }
       
       if(visit[cat][mouse][t]){
           return dp[cat][mouse][t];
       }
       visit[cat][mouse][t] = 1;
       if(cat == mouse){
           dp[cat][mouse][t] = 1;
           return 1;
       }
       if(mouse == 0){
           dp[cat][mouse][t] = -1;
           return -1;
       }
        
       if(t%2){/*cat move*/
           ans = -2;
           for(auto e : graph[cat]){
               if(e == 0){
                   continue;
               }
               dp[e][mouse][t+1] = helper(e,mouse,graph,t+1);
               if(dp[e][mouse][t+1] == 1){
                   return 1;
               }
               ans = max(ans,dp[e][mouse][t+1]);
           }
       }else{
           ans = 2;
           for(auto e : graph[mouse]){
               dp[cat][e][t+1] = helper(cat,e,graph,t+1);
               if(dp[cat][e][t+1] == -1){
                   return -1;
               }
               ans = min(ans,dp[cat][e][t+1]);
           }
       }
       
       return ans;
    }

    int catMouseGame(vector<vector<int>>& graph) {
        memset(visit, 0, sizeof(visit));
        memset(dp,0,sizeof(dp));
        int ans = helper(2, 1,graph,0);
        
        if (ans == 1) ans = 2;
        if (ans == -1) ans = 1;
        return ans;
    }
};
```
很蛋疼的一个题目,用数组dp[x][y],表示当前状态选中的人数与选中的车数之间的最小值。
x表示已经选中的worker的标记，y表示当前已经选中的bike的标记，
dp[x][y]表示当前选择标记中的最小值。

```
class Solution {
public:
    int mahaton(vector<int>& a,vector<int>& b){
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
    
    static bool bitTest(const int mask,int n){
        if((mask&(1<<n))>>n){
            return true;
        }else{
            return false;
        }
    }
    
    static int bitSet(int mask,int n){
        return mask|(1<<n);
    }
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int m = workers.size();
        int n = bikes.size();
        int mask1 = 1<<m;
        int mask2 = 1<<n;
        int ans = INT_MAX;
        vector<vector<int>> dp(mask1,vector<int>(mask2,INT_MAX));
        vector<vector<int>> dist(m,vector<int>(n,0));
        queue<pair<int,int>> qu;
        
        /*initial*/
        dp[0][0] = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0;j < n; ++j){
                dist[i][j] = mahaton(workers[i],bikes[j]);
            }
        }
        
        qu.push(make_pair(0,0));
        while(!qu.empty()){
            pair<int,int> curr = qu.front();
            qu.pop();
            int x = curr.first;
            int y = curr.second;
            
            for(int i = 0;i < m; ++i){
                for(int j = 0;j < n; ++j){                    
                    if(!bitTest(x,i)&&!bitTest(y,j)){
                        int x1 = bitSet(x,i);
                        int y1 = bitSet(y,j);
                                                
                        if((dp[x][y] + dist[i][j]) < dp[x1][y1]){
                            dp[x1][y1] = dp[x][y] + dist[i][j];                     
                            qu.push(make_pair(x1,y1));
                            if(x1 == mask1-1){
                                ans = min(ans,dp[x1][y1]);
                            }else{
                                qu.push(make_pair(x1,y1));
                            }
                        }                        
                    }
                }
            }
        }
        
        return ans;
    }
};
```
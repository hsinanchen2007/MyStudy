```
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> p(n,0);
        p[n-1] = cost[n-1];
        p[n-2] = cost[n-2];
        for (int i=n-3; i>=0; --i)
        {
            p[i] = cost[i] + min(p[i+1], p[i+2]);
        }
        
        return min(p[0],p[1]);
    }    
};
```

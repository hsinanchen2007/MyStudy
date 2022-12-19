```
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>> m;
        if(costs.size()<1)
            return 0;
        m.push_back(costs[0]);
        int i = 0;
        for(i=1; i<costs.size(); i++)
        {
            m.push_back(vector<int>(3, 0));
            m[i][0] = min(m[i-1][1], m[i-1][2]) + costs[i][0];
            m[i][1] = min(m[i-1][0], m[i-1][2]) + costs[i][1];
            m[i][2] = min(m[i-1][1], m[i-1][0]) + costs[i][2];
            
        }
        i--;
        return min(min(m[i][0], m[i][1]), m[i][2]);
    }
};
```

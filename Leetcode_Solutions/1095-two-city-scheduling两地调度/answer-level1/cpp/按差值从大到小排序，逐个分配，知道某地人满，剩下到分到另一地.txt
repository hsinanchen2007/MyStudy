```
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), cmp);
        int n1 = 0;
        int n2 = 0;
        int cost = 0;
        int N = costs.size()/2;
        for(int i=0; i<costs.size(); i++)
        {
            if(n1 == N)
            {
                cost += costs[i][1];
            }
            else if(n2 == N)
            {
                cost += costs[i][0];
            }
            else if(costs[i][0]<costs[i][1])
            {
                n1++;
                cost += costs[i][0];
            }
            else
            {
                n2++;
                cost += costs[i][1];
            }            
        }
        return cost;
    }
    static bool cmp(vector<int> v1, vector<int>v2)
    {
        return abs(v1[0]-v1[1]) > abs(v2[0]-v2[1]);
    }
};
```

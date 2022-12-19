```
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // 矢量加法：假设有三个矢量OA，OB，AB，求OA+OB等价于求OA+(OA+AB)=OA+(OA+OB-OA)=2OA+(OB-OA)
        // 翻译过来就是：全部人先去A城，再挑选一半人去B城，条件是A到B的费用最低
        int sum = 0;
        vector<int> ab;
        for(auto cost : costs)
        {
            sum += cost[0];
            ab.push_back(cost[1]-cost[0]);
        }
        sort(ab.begin(),ab.end());
        for(int i=0;i<ab.size()/2;i++)
        {
            sum += ab[i];
        }
        return sum;
    }
};
```
```
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        // 方法1(从后往前)：f[i] = cost[i] + min(f[i+1], f[i+2])
        int f0 = 0, f1 = cost[cost.size()-2], f2 = cost[cost.size()-1];
        for(int i = cost.size() - 3; i >= 0; --i) 
        {
            f0 = cost[i] + (f1 < f2 ? f1 : f2);
            f2 = f1;
            f1 = f0;
        }
        return (f1 < f2 ? f1 : f2);

        // 方法2（从前到后）： f[i] = cost[i] + min(f[i-1], f[i-2])
        // int f2 = cost[0], f1 = cost[1], f0 = 0;
        // for(int i = 2; i < cost.size(); ++i)
        // {
        //     f0 = cost[i] + (f1 < f2 ? f1 : f2);
        //     f2 = f1;
        //     f1 = f0;
        // }
        // return (f1 < f2 ? f1 : f2);
    }
};

```
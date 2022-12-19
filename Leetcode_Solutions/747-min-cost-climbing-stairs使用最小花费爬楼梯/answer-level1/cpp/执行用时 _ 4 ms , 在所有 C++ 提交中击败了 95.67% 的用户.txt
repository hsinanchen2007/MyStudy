### 解题思路
f(n) = min(f(n-1),f(n-2))+cost[n],理解这个公式你就知道怎么做了

### 代码

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        //f(n) = min(f(n-1),f(n-2))+cost[n]
        int cost1 = cost[0];
        int cost2 = cost[1];
        int cost3 = 0;
        int n = cost.size();
        for(int i = 2; i < n; ++i)
        {
            cost3 = min(cost1,cost2) + cost[i];
            cost1 = cost2;
            cost2 = cost3;

        }
        return min(cost1,cost2);
    }

};
```
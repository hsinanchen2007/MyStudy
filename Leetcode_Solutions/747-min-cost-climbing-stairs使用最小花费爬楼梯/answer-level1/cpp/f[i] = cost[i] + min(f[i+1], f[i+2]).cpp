### 解题思路
f[i] = cost[i] + min(f[i+1], f[i+2])
不知道为啥表现这么差

### 代码

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()==2)return min(cost[0],cost[1]);
        vector<int> ans;
        ans.push_back(cost[0]);
        ans.push_back(cost[1]);
        for(int i=2;i<cost.size();i++)ans.push_back(min(ans[i-1],ans[i-2])+cost[i]);
        return min(ans[cost.size()-2],ans[cost.size()-1]);
    }
};
```
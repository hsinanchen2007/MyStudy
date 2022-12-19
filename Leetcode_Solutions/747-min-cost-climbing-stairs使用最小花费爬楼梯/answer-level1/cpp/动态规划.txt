**动态规划**到达当前阶梯的花费，当前阶梯min(前一阶梯，前二阶梯)加上当前阶梯的花费
1. 到达索引0，花费为cost[0];
2. 到达索引1，花费为cost[1];
3. 到达索引2，花费为min(cost[2]+cost[0],cost[2]+cost[1]);
4. 到达索引n，花费为min(cost[n]+cost[n-2],cost[n]+cost[n-1]);
- n个阶梯，要爬到楼顶，可以从索引为n的阶梯爬（爬1步），也可以从索引为n-1的阶梯爬（爬2步），故实际为求到达min(,索引为n的阶梯花费，索引为n-1的阶梯的花费)

``` C++
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.empty()) return 0;
        int pre=cost[0],cur=cost[1];
        if(cost.size()==1) return cost[0];
        int res=cur;
        for(int i=2;i<cost.size();i++)
        {
            res=min(cost[i]+pre,cur+cost[i]);
            pre=cur;
            cur=res;
        }
        return min(pre,cur);
    }
};
```
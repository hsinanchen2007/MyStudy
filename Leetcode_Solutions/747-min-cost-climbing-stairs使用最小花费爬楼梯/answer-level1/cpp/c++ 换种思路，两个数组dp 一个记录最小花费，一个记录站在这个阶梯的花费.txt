```
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int* sum = new int[cost.size()];//答案最优解
        int* end = new int[cost.size()];//记录站在此阶梯的最小花费
        sum[0] = 0;
        end[0] = cost[0];
        sum[1] = min(cost[1], cost[0]);
        end[1] = cost[1];
        for(int i=2;i<cost.size();i++)
        {
            sum[i] = min(end[i-1], end[i-2]+cost[i]);//最优解要么是上一层阶梯，要么是上两层加当前层
            end[i] = min(end[i-1], end[i-2])+cost[i];//站在这个阶梯的解，上一层和上两层比较小的值加上当前层
        }
        return sum[cost.size()-1];
    }
};
```

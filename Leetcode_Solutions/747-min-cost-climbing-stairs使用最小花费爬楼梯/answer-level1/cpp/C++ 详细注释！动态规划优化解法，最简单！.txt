### 解题思路
建议去复习下斐波那契和爬楼梯算法，然后在这 2 个算法的基础上加上楼梯成本的计算就 OK 了！

详细过程见注释哦 ^ ^

### 代码

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 1. 从前往后，动态规划，本问题在爬楼梯问题的基础上增加了计算成本，原理是相同的。
        int climb_1 = cost[0];
        int climb_2 = cost[1];
        int climb_3 = 0;

        for (int i = 2; i < cost.size(); i++) {
            // 2. 爬到当前阶梯所需要的最小成本 = 爬前 1 级和前 2 级阶梯的最小成本 + 爬当前阶梯的成本
            climb_3 = min(climb_1, climb_2) + cost[i];

            // 3. 类似斐波那契数组的赋值方式
            climb_1 = climb_2;
            climb_2 = climb_3;
        }

        // 4. 最终是返回爬到顶部所需要的最小成本，climb_1 和 climb_2 在每一步都保持更新，知道楼梯顶部
        return min(climb_1, climb_2);
    }
};
```
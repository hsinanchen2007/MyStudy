### 解题思路
此处撰写解题思路
和爬楼梯思路类似，对于这里附加的体力值，到达楼顶后是不消耗体力值的，即对于n个台阶（不包括楼顶），体力最小就是n个台阶或n-1个台阶的最小值。
从低往顶写代码，先考虑特殊情况，n为0或1时，体力消耗为0；
n>=2的情况下，采用mincost向量来保存到达并包含当前台阶对应的最小值；
边界条件为mincost[0]=cost[0],mincost[1]==cost[1]；
当n>=3时，有mincost[n]=min{mincost[n-1], mincost[n-2]}+cost[n]。
代码实现如下：
### 代码

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> mincost;
        if(n == 0){return 0;}
        if(n == 1){return 0;}
        if(n>=2){
            mincost.push_back(cost[0]);
            mincost.push_back(cost[1]);
            for(int i=2; i<n; i++){
                mincost.push_back(min(mincost[i-1], mincost[i-2])+cost[i]);
            }
        }
        return min(mincost[n-1], mincost[n-2]);
    }
};
```
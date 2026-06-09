### 解题思路
该题最大的难度在于弄清楚题目想要表达啥意思。如果没有示例，题目就理解不了。
题意是说：求沿着梯子达到楼顶的最小花费。
注意歧义部分：
1）楼顶不是梯子的最后一阶。
2）如果梯子是0->n-1阶，从i到j阶这一步的花费是cost[i]，而不是cost[j]。
也就是说你每走一步，你都可以爬一个阶梯或者两个阶梯，而你的花费是，你出发的那个阶梯所对应的体力花费值。
因此如果你在阶梯i,
则你或者是从i-1上来的，这一步的花费为cost[i-1];
或者是从i-2上来的,这一步的花费为cost[i-2]。
假设在阶梯i-1,你的最小花费为minC[i-1]，在阶梯i-2,你的最小花费为minC[i-2]；
则爬上阶梯i，你的最小总花费为
min(minC[i-1]+cost[i-1],minC[i-2]+cost[i-2])。

### 代码

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
    
        if(cost.size()==2)
            return min(cost[0],cost[1]);

        vector<int> minC(cost.size()+1,0);
        minC[0] = 0;
        minC[1] = 0;
        for(int i=2;i<=cost.size();i++){
              minC[i] = min(minC[i-1]+cost[i-1],minC[i-2]+cost[i-2]);
        }
        return minC[cost.size()];        
    }
};
```
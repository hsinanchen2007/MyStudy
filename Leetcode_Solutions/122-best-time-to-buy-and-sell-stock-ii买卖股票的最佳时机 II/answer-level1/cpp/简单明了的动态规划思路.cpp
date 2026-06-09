### 解题思路
深受大神的启发，下面写一点我自己的见解
[@labuladong](/u/labuladong/)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp_i_0=0,dp_i_1=INT_MIN;
        for(int i=0;i<n;i++){
            int temp=dp_i_0;
            dp_i_0=max(dp_i_0,dp_i_1+prices[i]);
            dp_i_1=max(dp_i_1,temp-prices[i]);
            //这里用temp记录dp_i_0的原因是dp_i_0在上一步已经发生了变化
            //而我们要求dp_i_1所用到的应该是之前的dp_i_0
            //这里要着重说明一点就是在这里我们只用到了两个dp_i_0,dp_i_1
            //从而将空间复杂度降低为O(1)，为什么可以这样做呢？因为我们在
            //for循环外定义了两个dp_id的初始值（这里的初始值是相对于i=0而言的）
            //之所以可以只用两个记录就能将不同i对应的前一天的相关状态表示出来是因为
            //每个状态只与其前一天的状态有关
            //只要我们知道了相对于i=0时的初始值，那么进入for循环之后的pdp_i_0以及
            //dp_i_1的值是会随着i的变化实时更新的，所以就可以持续不断地求出新的
            //dp_i_0和dp_i_1的值来。
        }
        return dp_i_0;
    }
};

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp_i_0=0,dp_i_1=INT_MIN;
        for(int i=0;i<n;i++){
            int temp=dp_i_0;
            dp_i_0=max(dp_i_0,dp_i_1+prices[i]);
            dp_i_1=max(dp_i_1,temp-prices[i]);
        }
        return dp_i_0;
    }
};
```
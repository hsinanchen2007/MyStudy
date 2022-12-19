执行用时 :4 ms, 在所有 C++ 提交中击败了99.72%的用户
内存消耗 :7 MB, 在所有 C++ 提交中击败了100.00%的用户

### 解题思路
比起dp基本题型爬楼梯，此题变化在于，一次可以爬的楼梯数不确定，所以要增加一层循环
说明基本都在代码注释中了，主要一下两点：
1. dp[0]为什么=1
2. 为何先循环硬币种类，再循环dp[amount]

### 代码

```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n=coins.size();
        int dp[5001]={0},i,j;
        dp[0]=1;
        /*
        关于dp[0]：若amount=0，未给出硬币，则输出1，
        若amount=0，且给出了硬币，应该输出0，不过并没有设置这样一个测试点，估计是没意义
        在amount!=0,且有硬币时，dp[0]=1，并不是说凑amount=0有一种情况，而是考虑到之后的dp，比如amount=5，给出1，2，5三种硬币，dp[1]+=dp[0]，有一种凑法；dp[2]也有0+2这种凑法，中间要+=dp[0]，
        所以需要dp[0]=1
        */
        for(i=0;i<n;i++)
            for(j=coins[i];j<=amount;j++)
                //if(j>=coins[i])
                    dp[j]+=dp[j-coins[i]];
        /*
        错误1：两层循环反过来(先i从1-amount，内层j从0到coins.size-1)，还以5 1，2，5为例，
        计算dp[3]时会经历dp[3]+=dp[1]和dp[3]+=dp[2]，分别是3=1+2和3=2+1，重复计算
        */
        /*优化1：j从coins[i]开始，当j<coins[i]，不会增加新的解决方案
        */
        return dp[amount];
    }
};
```
### 解题思路
1. 描述最优解的特征
   - 序列`[3,3,5,0,0,3,1,4]` ，其最优解由【0,2] 和 [3,7]两部分的最佳值组成
   - 序列`[1,2,3,4,5]`，其最优解在区间[0,4]可以看作为 [0.4] 和 [4,4] 组
   - 因此 可以推出 递推式 res = max(res,DP[0,j]+DP[j+1,length]) j = 0,1,2,3...lenghth-1;

### 代码

```cpp
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;
        int profits[n];
        fill(profits,profits+n,0);
        int less = prices[0];
        for(int i=1;i<n;i++){
            profits[i] = max(prices[i]-less,profits[i-1]);
            less = min(less,prices[i]);
        }
        int res = profits[n-1],last,ma = prices[n-1];
        profits[n-1] = 0;
        for(int j=n-2;j>=0;j--){
            last = profits[j];
            profits[j] = max(profits[j+1],ma - prices[j]);
            ma = max(ma,prices[j]);
            res = max(res,last + profits[j]);
        }
        return res;
    }
};
```
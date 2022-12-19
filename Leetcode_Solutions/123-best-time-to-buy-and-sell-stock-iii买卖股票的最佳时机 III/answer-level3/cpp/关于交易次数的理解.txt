### 解题思路
如代码中注释所示

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)
        return 0;
        int dp_i10=0,dp_i11=-prices[0],dp_i20=0,dp_i21=-prices[0];//这里的第二位1或者2理解为可以进行交易的次数，将购买当做一次交易，而通过第一天的交易情况来进行初始化
        for(int i=1; i<n; i++)
        {
            int temp2=dp_i10;
            dp_i10=max(dp_i10,dp_i11+prices[i]);
            dp_i11=max(dp_i11,-prices[i]);//因为第一次购买初始为0
            dp_i20=max(dp_i20,dp_i21+prices[i]);
            dp_i21=max(dp_i21,temp2-prices[i]);
        }
        return dp_i20;//dp_i20意味某段时间可进行2次交易，但是实际做的交易可能为1次也可能为2次，此时手上不持有股票，所以表明已经完成了整个交易过程。
    }
};

```
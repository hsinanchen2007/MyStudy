![image.png](https://pic.leetcode-cn.com/b024ce2b8132c776ce509223fa38122563bae70fa6f9c50fc7e8bf9f1c15d498-image.png)

### 解题思路
1、假如当天比前一天的价格低，那么肯定在当天买进；
2、假如当天比前一天的价格高，那就可以考虑卖出，算出利润，叠加存起来，并更新买进时间为当天（当然这个买进时间并不是实际买进时间，还要重新经过1验证）；
3、重复1、2直到最后。

###代码思路
1、变量buy为买进时机，变量profit是不断更新的最高利润，初值为0，变量profitSave是每次买进卖出的利润；
2、从第二天开始遍历，假如当天比前一天价格低，那么更新buy，即当天买进；
3、假如当天比前一天价格高，那么直接卖出，更新profitSave，再更新最高利润profit，更新完后，profitSave清零，用于重新计算下次一买进卖出的利润。卖出当天定为重新买进时间（不是实际买进，会在循环中继续验证是否是最佳买进时间）；

###思考
举个例子，[1,2,3,4]，代码实现出来的意思就是第一天买进，第二天卖出并重新买进，第三天卖出并重新买进，第四天卖出并重新买进。但是实际上我们不会这样操作，而是第一天买进，第四天再卖出。本来觉得这样的代码很反人类，想改一下，不过再想一下，本来能预知第二天的情况就很反人类，就没纠结了。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 1;
        int profitSave = 0;
        int profit = 0;

        for(int i = 2; i <= prices.size(); i++){
            if(prices[i-1] < prices[buy-1]) buy = i;
            else{
                if(prices[i-1] - prices[buy-1] > profitSave){
                    profitSave = prices[i-1] - prices[buy-1];
                    profit += profitSave;
                    profitSave = 0;
                    buy = i;
                } 
            }
        }
        return profit;
    }
};
```
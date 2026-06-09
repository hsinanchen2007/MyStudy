**题意分析**
这道题求最大利润，实际上是求数组对之间的最大差值。另外题中强调了**股票价格按时间顺序储存**，这就限制我们只能用用后面的价格减去前面的价格。这样的条件下，我们求出俩个数的最大差值就行了。
**思路一**
最简单是用暴力法，先选定一个数，再用他后面的每个数分别减去这个数，求出它与它之后的各个数的差值。然后选出差值最小的即可。
**思路二**
因为这里有时间顺序，因此可以将求最大差值转换为求该数之前的最小值，然后更新差值即可。
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int min_prices = prices[0];
        int max = 0;
        for(int i = 1; i < (int)prices.size(); i++){
            if(min_prices > prices[i]){
                min_prices = prices[i];
            }
            else if(prices[i] - min_prices > max){
                max = prices[i] - min_prices;
            }
        }
        return max;
    }
};
```

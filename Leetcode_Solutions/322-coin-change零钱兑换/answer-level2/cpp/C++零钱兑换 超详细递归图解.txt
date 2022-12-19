![无标题.png](https://pic.leetcode-cn.com/7b520128b23cc583d408fb12b3609bd1d695d1f18a75eb508a51c88de8fc19b2-%E6%97%A0%E6%A0%87%E9%A2%98.png)


```
class Solution {
public:
    int coinChange(int whichCoin, vector<int> & coins, int amount)
    {

        if(amount == 0) return 0;
        if(amount > 0 && whichCoin < coins.size())
        {
            int leastNumber = INT_MAX;
            int numberFromChildren = 0;
            for(int howManyCoins = 0 ; amount >= howManyCoins *coins[whichCoin] ; howManyCoins++)
            {
                numberFromChildren = coinChange(whichCoin+1, coins, amount-howManyCoins*coins[whichCoin]);
                if(numberFromChildren != -1)
                {
                    leastNumber = min(leastNumber, numberFromChildren+howManyCoins);
                }
            }
            return leastNumber == INT_MAX ? -1 : leastNumber;
        }
        return  -1;
        
    }
    int coinChange(vector<int>& coins, int amount) {
        return coinChange(0, coins, amount);
    }
};
```
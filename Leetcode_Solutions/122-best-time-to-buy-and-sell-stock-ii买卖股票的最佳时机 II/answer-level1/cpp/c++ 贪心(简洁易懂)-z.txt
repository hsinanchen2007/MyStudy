### 解题思路
这道题这种解法其实就像是开了上帝视角，我提前知道第二天的价格，就相当于我知道第二天会涨价，那我今天肯定会买入，第二天马上卖出就能赚钱，但是也就存在同一天卖出又买入的情况，但是题目并没有进行限制

贪心：即每一步都采取最优解，在本题中就是每一天都有钱赚，或者至少不亏钱

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    
        if(prices.size()==0) return 0;//按理说可以不写这个，但是遇到了一个测试用例是[],debug的时候给我整吐了，咱也不知道他要干嘛

        int profit=0;
       for(int i=0;i<prices.size()-1;i++)  
            if(prices[i+1]>prices[i])
            profit+=prices[i+1]-prices[i]; //如果第二天卖出能赚钱的话，利润+=明天的价格减去今天的价格
       
       return profit;
    }
};
```
和买卖股票的最佳时机III类似，只不过k变成了动态而不是恒定值2，所以我们可以修改状态为动态的，每一天的情况还是那几种，买还是不买，卖还不是不卖。
所以我的想法就是直接用一个vector来存放我们的状态，当k==2时，我们可以推出存在4个状态，即第一次买入，第一次卖出，第二次买入，第二次卖出。
所以vector长度应为2xk,但是为了处理方便，我们可以扩展为2xk+1，存入第一个为0，因为每次第一次买入的时候钱是0；这是为了泛化加的。
还有一个需要注意的是，当k特别大时，我们在运用这个算法会达到很大的复杂度O(NK),然而我们发现，K>=prices.size/2时，即我们可以针对每一个股票进行操作，转化为了求最大和问题，所以我们可以针对k特别大的时候单独讨论，减低复杂度。
ps（一开始我没有单独写出k特别大时候的算法，提交a不了所有解。。。。）
```
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty() || k==0) return 0;
        if(k >= prices.size()/2)
            return tanxin(prices);
    //进行初始化，其他状态全部初始化为最小值
        vector<int>res(2*k + 1,INT_MIN);
        res[0] = 0;
        res[1] = -prices[0];

        for(int i=1;i<prices.size();++i) {
            for(int j=1; j< 2*k+1; j+=2) {
                res[j] = max(res[j], res[j-1]-prices[i]);
                res[j+1] = max(res[j+1], res[j]+prices[i]);
            }
        }
        return max(0,res[2*k]);
    }

    int tanxin(vector<int>& prices) {
        int max = 0;
        for(int i=1; i<prices.size(); i++) {
            if(prices[i] > prices[i-1])
                max += prices[i] - prices[i-1];
        }
        return max;
    }
};
```

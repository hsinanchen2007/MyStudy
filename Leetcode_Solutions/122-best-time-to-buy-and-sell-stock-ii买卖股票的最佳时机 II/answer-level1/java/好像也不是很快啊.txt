这是我的算法
```
 int result = 0;
         //持有金额
        int flag = 0;
        // 是否持有
        boolean hold = false;
        for (int i = 0; i < prices.length - 1; i++) {
            // 没有可以买
            if ((prices[i] < prices[i + 1]  || prices[i] == 0)&&hold==false) {
                flag = prices[i];
                hold = true;
            }
            // 有票，只能卖
            else if (prices[i] > prices[i + 1] && hold) {
                result += prices[i] - flag;
                flag = 0;
                hold = false;
            }

        }
        // 到最后还有股票 直接卖
        if (hold) {
            result += prices[prices.length - 1] - flag;
            hold = false;
        }
        return result;
```
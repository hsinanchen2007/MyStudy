结题思路：
1.买入的是最低价格。
2.卖出的是最高价格。
3.买入的时间是在卖出之前。
4.没有符合要求的返回收益值为0.

具体流程：
    int maxProfit(int* prices, int pricesSize){
        int i, j;
        int buyin, buyout, profit;
        int middle_value;
        if (pricesSize <= 1) {
            return 0;
        }
        buyin = buyout = prices[0];//买入和卖出是同一天.
        profit = 0;//收益为0.

        for (i = 1; i < pricesSize; i++) {
            buyout = prices[i];             //当天卖出价格.
            middle_value = buyout - buyin;  //当天收益值
            if (middle_value > profit) {    //如果收益值比默认的收益值高,进行更新
                profit = middle_value;
            }
            if (prices[i] < buyin) {        //如果买入价格比默认的低,进行更新.
                buyin = prices[i];
            }
        }
        return profit;
    }
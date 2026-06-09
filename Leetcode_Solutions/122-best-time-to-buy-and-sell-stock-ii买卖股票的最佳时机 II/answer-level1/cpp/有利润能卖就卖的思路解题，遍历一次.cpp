有利润能卖就卖的思路和第一天买，过几天利润最高再卖，获得的利润是一样的，因为中间错过了一次卖出，这个不能和实际生活中买股票来想，这个是理想化的，利润最大化，就是有利润就卖，就买

    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
        {
            return 0;
        }

        int MaxProfit = 0;
        for(int i = 0 ; i < prices.size()-1;i++)
        {
            if(prices[i] < prices[i+1])
            {
                MaxProfit+= prices[i+1] - prices[i];
            }
        }
        return MaxProfit;
    }
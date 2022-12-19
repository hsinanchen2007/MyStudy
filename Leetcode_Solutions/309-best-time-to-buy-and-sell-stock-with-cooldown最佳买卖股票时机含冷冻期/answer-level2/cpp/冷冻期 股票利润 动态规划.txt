```
    int maxProfit(vector<int>& prices) {
        if(prices.empty())return 0;
        int mc0=0;//保存的前天卖出利润
        int mr2=mc0-prices[0];//今天买入的利润
        int mc2=0;//今天卖出的利润
        for(int i=1;i<prices.size();i++)
        {
            mr2=max(mr2,mc0-prices[i]);
            mc0=mc2;
            mc2=max(mc2,mr2+prices[i]);
        }
        return mc2;
    }
```

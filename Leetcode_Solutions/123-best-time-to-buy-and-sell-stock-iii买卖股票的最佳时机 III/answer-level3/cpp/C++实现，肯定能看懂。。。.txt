```
//max_Profit_back和max_Profit_front是由121题改造的。

//求prices这个向量，num这一点到终点的股票最大值（区间最大值）

int max_Profit_back(vector<int>& prices, int num){
    if(prices.size()-num <= 1){
        return 0;
    }
    int max_price = 0;
    int tag = num;//tag指针，指向当前最大price的天数（买股票的那一天）
    for(int i=num+1; i<prices.size(); ++i){
        if(prices[i] > prices[tag]){
            int tmp = prices[i] - prices[tag];
            max_price = max(max_price, tmp);
        } else{
            tag = i;//如果当天比tag小，那么tag就要移动，因为tag指向买股票的那一天，肯定要小。
        }
    }
    return max_price;
}

//求prices这个向量，起点到num这一点的股票最大值（区间最大值）
int max_Profit_front(vector<int>& prices, int num){
    if(num < 1){
        return 0;
    }
    int max_price = 0;
    int tag = 0;//tag指针，指向当前最大price的天数（买股票的那一天）
    for(int i=1; i<=num; ++i){
        if(prices[i] > prices[tag]){
            int tmp = prices[i] - prices[tag];
            max_price = max(max_price, tmp);
        } else{
            tag = i;//如果当天比tag小，那么tag就要移动，因为tag指向买股票的那一天，肯定要小。
        }
    }
    return max_price;
}


int maxProfit(vector<int>& prices) {
    int max_profit = 0;
    //遍历数组，将数组分为两部分，分别求两边最大值之和，遍历完求得全局最大。
    for(int i=0;i<prices.size(); ++i){
        max_profit = max(max_profit,max_Profit_front(prices, i) + max_Profit_back(prices, i+1));
    }
    return max_profit;
}
```





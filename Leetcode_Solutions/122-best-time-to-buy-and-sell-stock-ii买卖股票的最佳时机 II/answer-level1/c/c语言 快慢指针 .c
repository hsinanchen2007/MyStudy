int maxProfit(int* prices, int pricesSize){
    int slow = 0;
    int fast = 1;
    int ret = 0;

    while(pricesSize <= 1){
        return 0;
    }

    while(fast < pricesSize){
        if(prices[fast] > prices[slow]){
            ret = ret + prices[fast] - prices[slow];
        }
        slow = fast;
        fast++;
    }
    return ret;
}


121. 买卖股票的最佳时机   这题同样也可以快慢指针
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/cyu-yan-kuai-man-zhi-zhen-by-lcqf/
/*允许多次买卖*/
/*找到每个递增的范围，计算两个边界差值，最后将所有差值相加*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0||prices.size()==1)return 0;
        int res = 0;//结果
        int minnum = prices[0];//第一个数为最小值
        for(int i = 1;i < prices.size();i ++)//从第二个数开始
        {
			//如果当前数比上一个数小，则卖出股票，然后重新买入，更新最小值
            if(prices[i] < prices[i - 1])
            {
                res += prices[i - 1] - minnum;
                minnum = prices[i];
            }
			//如果达到最后一个位置，则卖出股票，计算结果
            if(i == prices.size()-1)
                res += prices[i] - minnum;
        }
        return res;
    }
};

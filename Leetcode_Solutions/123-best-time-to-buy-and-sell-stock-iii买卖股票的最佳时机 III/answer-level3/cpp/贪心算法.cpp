两次交易可以简化为一次最优操作加一次套利操作。套利操作为买入前或卖出后的一次完整买卖交易，或者买卖中间做一次T

    //--------------------------------------贪心算法求解证明---------------------------------------
    //maxProfit1(vector<int>& prices, int& buy, int& sell) 获取一次交易最大利润及买卖日期
    //若只交易了一次，直接由maxProfit1获取最大利润，设交易为(b0,s0)
    //若交易了两侧获取最大利润，设先后两次交易为（b1,s1）、(b2,s2)，单次利润肯定不超过只进行一次交易的利润
    //很容易得到结论：
    //  (1)若s1==s0,则b1==b0;
    //  (2)若b2==b0,则s2=s0;
    //  (3)若b0>s1, 则(b2,s2)=(b0,s0);
    //  (4)若s0<b2, 则(b1,s1)=(b0,s0)。
    //此外，必然存在条件(prices[b0]<=prices[bi] || prices[s0]>=prices[si]) (i=1,2)
    //--------------------------------------------------------------------------------------------
    //接下来，证明 (b0==b1||b0==b2) && (s0==s1||s0==s2)：
    //  若b0>s1 || s0<b2, 由结论(3)(4)可证；
    //  若b0<s1 && s0>b2:
    //----------------------------证明b0==b1----------------------------
    //      若prices[b0]<=prices[b1]， 由于b0<s1，      b1取b0时(b1,s1)利润更大，即b1=b0
    //      否则prices[b0]>prices[b1]，由于s0>b2>s1>b1，b0取b1时(b0,s0)利润更大，即b0=b1
    //----------------------------证明s0==s2----------------------------
    //      若prices[s0]>=prices[s2]， 由于s0>b2，      s2取s0时(b2,s2)利润更大，即s2=s0
    //      否则prices[s0]<prices[s2], 由于b0<s1<b2<s2，s0取s2时(b0,s0)利润更大，即s0=s2
    //--------------------------------------------------------------------------------------------
    //因此，两次交易可以简化为一次最优操作加一次套利操作
    //套利操作为b0前交易一次或s0后交易一次，或者b0与s0之间进行一次做T（先卖后买）
    //--------------------------------------贪心算法证明结束---------------------------------------

class Solution {
private:

    int maxProfit1(vector<int>& prices, int& buy, int& sell) { //一次交易最大利润，并获取买卖日期
        if(prices.size()<=1) return 0;
        int minPrice = prices[0];
        int curProfit = 0;
        int maxProfit = 0;
        int curBuy = 0;
        for(int i=1; i<prices.size(); i++) //第i天卖出的最大利润
        {
            if(prices[i]<minPrice)
            {
                minPrice = prices[i];
                curProfit = 0;
                curBuy = i;
            }
            else
            {
                curProfit = prices[i] - minPrice;
                if(curProfit>maxProfit)
                {
                    maxProfit = curProfit;
                    buy = curBuy;
                    sell = i;
                }
            }
        }
        return maxProfit;
    }
public:

    int maxProfit(vector<int>& prices) {
        int buy  = 0;
        int sell = 0;
        int ret = maxProfit1(prices, buy, sell); //一次交易最大利润，并获取买卖日期
        if(buy==sell) return 0; //未能进行交易，获利0
        vector<int> tempBefore(prices.begin(), prices.begin()+buy);         //本次交易前有一次套利，先买后卖
        vector<int> tempMiddle(prices.begin()+buy+1, prices.begin()+sell);  //本次交易过程中一次做T，先卖后买
        if(tempMiddle.size()) reverse(tempMiddle.begin(), tempMiddle.end());
        vector<int> tempAfter(prices.begin()+sell+1, prices.end());         //本次交易后有一次套利，先买后卖
        int profitBefore = maxProfit1(tempBefore, buy, sell);
        int profitMiddle = maxProfit1(tempMiddle, buy, sell);
        int profitAfter = maxProfit1(tempAfter, buy, sell);
        if(profitBefore>profitMiddle) profitMiddle = profitBefore;
        if(profitAfter>profitMiddle)  profitMiddle = profitAfter;
        ret += profitMiddle;
        return ret;
    }
};
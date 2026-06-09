此问题可划分为两个子问题 sub[0:n] = max(sub[0:i]+sub[i:n]) 其中i 为 0->n;

得到这个之后，很容易想出来如何保存子问题的解，一个正向求解，一个逆向求解，和问题I一样，代码如下，时空复杂度均为O(n)

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int *dp=new int[prices.size()];
        int *dp_2=new int[prices.size()];
        int ans=0;
        left(prices,dp);
        right(prices,dp_2);
        for(int i=0;i<prices.size();i++)
            ans=max(ans,dp[i]+dp_2[i]);
        return ans;

    }

    void left( vector<int> prices, int *&dp)
    {
        int ans=0;
        int low=prices[0];
        for(int i=0;i<prices.size();i++)
        {
            ans=max(ans,prices[i]-low);
            dp[i]=ans;
            low=min(low,prices[i]);
        }
    }
    void right(vector<int> prices,int *&dp)
    {
        int ans=0;
        int high=prices[prices.size()-1];
        for(int i=prices.size()-1;i>=0;i--)
        {
            ans=max(ans,high-prices[i]);
            dp[i]=ans;
            high=max(high,prices[i]);
        }
    }
};

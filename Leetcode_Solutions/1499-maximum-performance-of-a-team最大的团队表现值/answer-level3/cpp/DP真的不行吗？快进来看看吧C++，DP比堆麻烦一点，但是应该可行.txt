
**普通数据都过了，但是遇到大数过不了，我不晓得是哪个地方出了问题， 大家帮我找找漏洞，思路应该是没问题的**
```
#define ll unsigned long long
#define mod 1000000007
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        //dp[i][j].first:前i个工程师恰好选择j个项目最大团队表现值对应的speed和
        //dp[i][j].second:前i个工程师恰好选择j个项目最大团队表现值对应的最小efficiency
        pair<ll,ll> dp[n+1][n+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<=i;j++)
            {   //dp的初始化：
                if(j==0||i==0)
                {
                    dp[i][j].first=0;
                    dp[i][j].second=pow(10,8);
                }
                else
                {   
                    //如果选择dp[i][j],分别求这个时候的first和second
                    ll xuanfirst=dp[i-1][j-1].first+speed[i-1];
                    ll xuansecond=min(dp[i-1][j-1].second,(ll)efficiency[i-1]);
                    //如果选择dp[i][j],那么这个时候的最大团队值是：
                    ll xuan=xuanfirst*xuansecond;
                    
                    ll bu=0,bufirst,busecond;
                    //如果选择dp[i][j],分别求这个时候的first和second,和最大团队值
                    //要注意！！i>j才能不选,如果i==j，那么一定会选dp[i][j];
                    if(i>j)
                    {
                        bufirst=dp[i-1][j].first;
                        busecond=dp[i-1][j].second;
                        bu=bufirst*busecond;
                    }
                    //判断dp[i][j]到底是选还是不选，要注意，如果
                    //选择和不选的团队最大值相同，那么肯定要选择second大的那一个
                    if(xuan>bu)
                    {
                        dp[i][j].first=xuanfirst;
                        dp[i][j].second=xuansecond;
                    }
                    else if (xuan==bu)
                    {
                        dp[i][j].first=xuanfirst<bufirst?xuanfirst:bufirst;
                        dp[i][j].second=xuansecond>busecond?xuansecond:busecond;
                    }
                    else
                    {
                        dp[i][j].first=bufirst;
                        dp[i][j].second=busecond;
                    }
                }
                
            }
        }

        //答案是前n个选0个、选1个、选2个、选3个......选k个的最大值！
        ll Max=0;
        for(int i=0;i<=k;i++)
            if(Max<dp[n][i].first*dp[n][i].second)
                Max=dp[n][i].first*dp[n][i].second;
       return Max%mod;
    }
};
```

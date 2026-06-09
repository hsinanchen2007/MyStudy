### 解题思路
此处撰写解题思路
动态规划算法，时间复杂度较高，空间复杂度低
### 代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int maxint=99999;
        sort(coins.begin(),coins.end());
        coins.insert(coins.begin(),0);
        int n=coins.size();
        int cnt[n][amount+1];
        for(int i=0;i<n;i++)
        {
            for(int m=0;m<=amount;m++)
            {
                if(m==0)
                cnt[i][m]=0;
                else if(i==0)
                cnt[i][m]=maxint;
                else
                {
                    int k=m/coins[i];
                    if(k==0)
                    {
                        cnt[i][m]=cnt[i-1][m];
                    }
                    else
                    {
                        cnt[i][m]=cnt[i-1][m];
                        for(int t=1;t<=k;t++)
                        {
                            if(cnt[i][m-t*coins[i]]+t<cnt[i][m])
                            cnt[i][m]=cnt[i][m-t*coins[i]]+t;
                        }
                    }
                }
            }
        }
        if(cnt[n-1][amount]>=maxint)
        return -1;
        else
        return cnt[n-1][amount];
    }
};
```
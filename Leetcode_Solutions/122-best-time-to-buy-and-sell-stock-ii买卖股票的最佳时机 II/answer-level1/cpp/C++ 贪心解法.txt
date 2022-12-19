贪心准则：当数列开始严格递增时，用一个指针记录递增的起始位置，即为买入时间。然后判断递增结束的位置，即为卖出时间，递增一结束，就将总值进行更新，并重置指针的初值。另外注意，数组边界的处理。

```
int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len==1)
            return 0;
        int sum=0,low=-1;
        for(int i=0;i<len;i++)
        {
            if(i==len-1)
            {
                if(prices[i-1]<prices[i])
                {
                    sum+=prices[i]-prices[low];
                }
                break;
            }
            if(prices[i]<prices[i+1])
            {
                if(low==-1)
                {
                    low=i;
                }
                continue;

            }
            else
            {
                if(low==-1)
                {
                    continue;
                }
                else
                {
                    sum+=prices[i]-prices[low];
                    low=-1;
                }
            }
        }
        return sum;
    }
```

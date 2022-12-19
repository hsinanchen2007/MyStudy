## 解题思路
用一次遍历解决问题,在遍历的过程中
通过比较把最小值给记录下来
通过判断潜在的最大收益与ret的大小关系
得到最终结果

```
int maxProfit(vector<int>& prices) {
        int minvalue=100000;
        int ifprofit=0;
        int ret=0;
        for(int i=0;i<prices.size();++i)
        {
            if(minvalue>prices[i])
            {
                minvalue=prices[i];
            }
            ifprofit=prices[i]-minvalue;
            if(ret<ifprofit)
            {
                ret=ifprofit;
            }
        }
        return ret;
    }
```

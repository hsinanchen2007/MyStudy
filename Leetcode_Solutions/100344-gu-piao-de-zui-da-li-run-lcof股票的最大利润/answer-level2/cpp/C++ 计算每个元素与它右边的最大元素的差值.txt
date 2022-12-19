

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        //计算每个元素与它右边的最大元素的差值
        int res = 0;
        vector<int> temp(prices.size());//temp[i]表示prices[i]右边的最大元素的大小;
        temp[temp.size()-1] = prices[temp.size()-1];
        for(int i = temp.size()-2;i>=0;--i)
            temp[i] = max(prices[i],temp[i+1]);
        for(int i = 0;i < prices.size();++i)
            res = max(res,temp[i]-prices[i]);
        return res;
    }
};
```
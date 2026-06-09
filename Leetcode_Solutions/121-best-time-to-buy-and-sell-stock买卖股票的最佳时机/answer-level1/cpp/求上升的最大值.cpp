### 解题思路
只需要关注股票曲线上升的最大值即可，设置一个区间，起点i长度j：（首项i 末项i+j）
若i+j项大于i项：判断是否为最大值，然后区间长度j加1起点i不变
若i+j项小于i项：令起点i为第i+j项（从第i+j项开始继续寻找最大值），区间长度j归为1

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=prices.size();
        int max=0;
        int i=0;
        int j=1;
        for(;i+j<l;)
        {
            if(prices[i+j]>prices[i])
            {
                if(prices[i+j]-prices[i]>max)max=prices[i+j]-prices[i];
                j++;
            }
            else 
            {
                i=i+j;
                j=1;
            }
        }
        return max;
    }
};
```
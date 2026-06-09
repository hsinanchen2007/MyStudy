### 解题思路
维护一个长度与prices相同的数组，每个成员记录了在他之前最低的价格，同时用当前的价格减去最低价格，并与当前最高价格进行比较，只要for循环一轮就能得出最大收益。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        vector<int> a(len);
        int min=65535;
        int max=0;
        for(int i=0;i<len;i++){
            if(min>prices[i]){
                min=prices[i];
                a[i]=min;
            }
            else
               a[i]=min;
            if(prices[i]-a[i]>max)
                max=prices[i]-a[i];
        }
        return max;
    }
};
# - ```
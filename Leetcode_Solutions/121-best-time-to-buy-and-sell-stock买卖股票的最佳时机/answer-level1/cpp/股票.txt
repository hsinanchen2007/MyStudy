### 解题思路
动态规划问题

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int resmax=0;
        if(prices.size()==0) return 0;
        int nowmin=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<prices[i-1] && nowmin>prices[i]) nowmin=prices[i];
            else if(prices[i]-nowmin>resmax) resmax=prices[i]-nowmin;
        }
        return resmax;
    }
};
```
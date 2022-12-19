### 解题思路
采用贪心的思想，每当`prices[i]-prices[i-1]`时，便进行一次交易。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int sum = 0;

        if(len == 0){
            return 0;
        }
        
        for(int i = 1; i < len; ++i){
            int temp = prices[i] - prices[i - 1];
            if(temp > 0){
                sum += temp;
            }
        }

        return sum;
    }
};
```
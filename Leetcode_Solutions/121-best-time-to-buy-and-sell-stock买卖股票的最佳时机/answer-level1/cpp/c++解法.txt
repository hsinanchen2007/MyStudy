### 解题思路
记录当前所遇到过的最小值，如果后面的值比cur_min大的话，就计算max（result，prices[i]-cur_min）。否则就cur_min=prices[i]。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }
        int result=0;
        int cur_min=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>cur_min){
                result=max(result,prices[i]-cur_min);
            }else if(prices[i]<cur_min){
                cur_min=prices[i];
            }
        }
        return result;
    }
};
```
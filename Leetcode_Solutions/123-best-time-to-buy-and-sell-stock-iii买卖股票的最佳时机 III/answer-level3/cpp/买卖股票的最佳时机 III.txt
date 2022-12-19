### 解题思路
状态转移

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p20 = 0;
        int p21 = INT_MIN;
        int p10 = 0;
        int p11 = INT_MIN;
        for(auto price:prices){
            p20 = max(p20,p21 + price);
            p21 = max(p21,p10 - price);
            p10 = max(p10,p11 + price);
            p11 = max(p11,-price);
        }

        return p20;
    }
};
```
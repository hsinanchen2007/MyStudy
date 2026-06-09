### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size=prices.size();
        int ans=0;
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                ans=max(ans,prices[j]-prices[i]);
            }
        }
            
        return ans;

    }
};
```
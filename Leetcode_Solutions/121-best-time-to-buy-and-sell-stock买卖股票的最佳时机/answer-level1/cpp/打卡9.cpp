### 解题思路
  思路很简单，就是在左边找到最小值，右边找到最大值。它们的差就是答案。因为只能交易一次。
  因此就在遍历的时候，去看这个数是比左边最小值大还是小，如果大，那就求它们差值。如果小，那就跟新左边最小值就好了。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxn = 0;
        int n = prices.size();
        if(n <= 1)return 0;
        int premin = prices[0];
        for(int i = 1 ; i < n ; i++){
            maxn = max(maxn , prices[i] - premin);
            premin = min(premin , prices[i]);
        }
        return maxn;
    }
};
```
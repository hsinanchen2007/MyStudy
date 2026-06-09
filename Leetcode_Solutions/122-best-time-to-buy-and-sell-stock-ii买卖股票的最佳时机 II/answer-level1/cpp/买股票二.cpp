### 解题思路
写了半天也写不对，还写了一大堆，最后看了下答案，贪心算法学到了，不过也有一点题意理解的问题，可以当天卖出当天买进，不过解题思路还是差远了。

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, n = prices.size();
       for(int i = 1;i<n;++i)
       {
           maxProfit += max(0,prices[i]-prices[i-1]);
       }
       return maxProfit;
    }
};
```
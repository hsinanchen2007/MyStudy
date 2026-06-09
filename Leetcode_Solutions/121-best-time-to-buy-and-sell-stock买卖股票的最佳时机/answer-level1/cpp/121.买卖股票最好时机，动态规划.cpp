### 解题思路
![image.png](https://pic.leetcode-cn.com/31ef263a807845d2aedc1c8a7d7537eb0348494945aaf1172025be1e492d989e-image.png)

T(n) = max(T(n-1), p[i] - min_num);

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int min_num = prices[0];
        int len = prices.size();
        int res = 0;
        for (int i = 1; i < len; i++) {
            if (prices[i] < min_num) {
                min_num = prices[i];
                continue;
            }
            res = max(res, prices[i] - min_num);
        }
        return res;
    }
};
```
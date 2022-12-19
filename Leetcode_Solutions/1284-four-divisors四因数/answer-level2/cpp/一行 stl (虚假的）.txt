![image.png](https://pic.leetcode-cn.com/da4aeb2c13086de0e69b769a363e094e94f039772c25e5c2e1b7f63d600b51ce-image.png)

```c++
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, [](int init, int val) {
          auto k = sqrt(val);
          auto cnt = 0;
          auto sum = 0;
          for (int i = 2; i <= k; ++i) {
            if (val % i == 0) {
              cnt ++;
              sum += i;
              if (i != k) {
                cnt ++;
                sum += val / i;
              }
              if (cnt > 2) return init;
            }
          }
          return cnt == 2 ? init + sum + 1 + val : init;
        });
    }
};
```

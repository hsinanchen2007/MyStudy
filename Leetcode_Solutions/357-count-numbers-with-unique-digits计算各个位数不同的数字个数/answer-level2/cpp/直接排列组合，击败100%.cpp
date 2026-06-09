### 解题思路


### 代码

```cpp
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans;
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 10;
        }
        ans += 10;
        for (int k = 2; k <= n; k++) {
            int sum = 9;
            for (int i = 2; i <= k; i++) {
                sum = sum * (11 - i);
            }
            ans += sum;
        }
        return ans;
    }
};
```
## 思路

### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```cpp
class Solution {
public:
    int numWays(int n) {
        if (n == 0 || n == 1) return 1;
        int a = 1, b = 2, res = 2;
        for (int i = 3; i <= n; ++i) {
            res = (a + b) % 1000000007;
            a = b;
            b = res;
        }
        return res;
    }
};
```
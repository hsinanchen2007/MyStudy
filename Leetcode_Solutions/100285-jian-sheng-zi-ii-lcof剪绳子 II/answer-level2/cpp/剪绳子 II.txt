### 解题思路
无法动态规划，直接数学归纳，3最优选；

### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4) return n-1;
        if (n == 4) return 4;
        long int ans = 1;
        while (n > 4) {
            n -= 3;
            ans = (ans * 3) % 1000000007;
        }
        if (n != 0) ans = (ans * n) % 1000000007;
        return ans;
    }
};
```
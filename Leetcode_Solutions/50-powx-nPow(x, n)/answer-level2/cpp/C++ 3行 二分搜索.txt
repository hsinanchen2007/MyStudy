```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if(abs(n) < 2) return n ? n > 0 ? x : 1/x : 1;
        auto root = myPow(x, floor((double)n/2));
        return (n % 2 ? x : 1) * root * root;
    }
};
```
- 时间复杂度：O(logN)
- 空间复杂度：O(logN)
- x^4 = x^2 ** x^2, x^5 = x^2 * x^2 * x, 借此方法可以缩减计算量
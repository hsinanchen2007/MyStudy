求有K行，可以的到不等式
(2*k-1)^2<8*n+1<=(2*k+1)^2
化简后
k-1<(sqrt(8*n+1)-1)/2<=k
所以k等于(sqrt(8*n+1)-1)/2向下取整
```
class Solution {
public:
    int arrangeCoins(int n) {
        return floor((sqrt(8.0 * n + 1) - 1) / 2);
    }
};
```
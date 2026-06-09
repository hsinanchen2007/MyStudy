首先，由于本题基于阶乘，所以显而易见 **偶数的数量远大于5的数目**。
要想获得尾数的 0，需要 **偶数和5相乘**。

代码如下：
```
class Solution {
    public int trailingZeroes(int n) {
        int ans = 0;
        while(n >= 5) {
            ans += n / 5;
            n /= 5;
        }
        return ans;
    }
}
```

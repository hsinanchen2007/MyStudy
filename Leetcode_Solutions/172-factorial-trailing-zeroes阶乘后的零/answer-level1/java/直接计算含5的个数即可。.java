先用对数函数计算出小于n的5的最大次方数c：log(n)/log(5)。
然后依次计算n中包含多少个5^1、5^2……5^c，累加即可。

```
class Solution {
    public int trailingZeroes(int n) {
        int c = (int)(Math.log(n) / Math.log(5));
        int ans = 0;
        for (int i = 1; i <= c; i++) {
            int d = (int)(Math.pow(5,i));
            ans += n / d;
        };
        return ans;
    }
}
```

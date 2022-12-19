```
class Solution {
public:
    using ul = unsigned long;
    ul highBit(int n) {
        ul res = 0;
        while (n > 0) {
            res = n;
            n &= n - 1;
        }
        return res;
    }
    ul lowBit(int n) {
        return n & -n;
    }
    ul mask(int n) {
        ul hi = highBit(n);
        ul lo = lowBit(n);
        return ((hi << 1) - 1) ^ (lo - 1);
    }
    int binaryGap(int N) {
        if ((N & N - 1) == 0) return 0;
        ul n = ~N;
        n &= mask(N);
        int res = 1;
        while (n > 0) {
            ++res;
            n &= n << 1;
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/d9e9dabcde691d7b36a4045e24bbc1151465a4e79fc6d87ca18816dbc278d709-image.png)

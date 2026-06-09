### 解题思路
1，对于一个数，有多少个丑数小于等于该数是可以快速计算出来的
2，因此可以用二分搜索定位该数

### 代码

```cpp
class Solution {
public:
    long LCM(long a, long b) {
        return a * (b / __gcd(a, b));
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        long ab = LCM(a, b);
        long ac = LCM(a, c);
        long bc = LCM(b, c);
        long abc = LCM(ab, c);
        long l = min(a, min(b, c));
        long r = 2 * 10e9;
        while (l < r) {
            long m = l + (r - l) / 2;
            long count = m / a + m / b + m / c - m / ab - m / ac - m / bc + m / abc;
            if (count < n) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};
```

![image.png](https://pic.leetcode-cn.com/230afeee6b3c60f9bec17d290c7b3260c9cc9a9618ac14d891f4abdbc641708b-image.png)

#### 方法：分数类

**思路**

因为给定的两个数字都表示一个分数，所以我们需要一个分数类去处理这两个分数。它应该能帮助我们将两个分数加起来，并且保证答案为最简形式。

**算法**

我们需要理解给定的两个分数，最困难的问题是如何表示它们。

比如说我们有一个字符串 `S = "0.(12)"`。它代表（定义 $r = \frac{1}{100}$）：

$$
S = \frac{12}{100} + \frac{12}{10000} + \frac{12}{10^6} + \frac{12}{10^8} + \frac{12}{10^{10}} + \cdots
$$

$$
S = 12 * (r + r^2 + r^3 + \cdots)
$$

$$
S = 12 * \frac{r}{1-r}
$$

其中 $(r + r^2 + r^3 + \cdots)$ 是一个等比数列求和问题。

总而言之，对于长度为 $k$ 的重复部分 $x$，会对答案有 $\frac{xr}{1-r}$ 的贡献，其中 $r = 10^{-k}$。

另外两部分就更容易计算了，因为它们仅仅是对数值的简单翻译。

```java [QFRcSJ8K-Java]
class Solution {
    public boolean isRationalEqual(String S, String T) {
        Fraction f1 = convert(S);
        Fraction f2 = convert(T);
        return f1.n == f2.n && f1.d == f2.d;
    }

    public Fraction convert(String S) {
        int state = 0; //whole, decimal, repeating
        Fraction ans = new Fraction(0, 1);
        int decimal_size = 0;

        for (String part: S.split("[.()]")) {
            state++;
            if (part.isEmpty()) continue;
            long x = Long.valueOf(part);
            int sz = part.length();

            if (state == 1) { // whole
                 ans.iadd(new Fraction(x, 1));
            } else if (state == 2) { // decimal
                 ans.iadd(new Fraction(x, (long) Math.pow(10, sz)));
                 decimal_size = sz;
            } else { // repeating
                 long denom = (long) Math.pow(10, decimal_size);
                 denom *= (long) (Math.pow(10, sz) - 1);
                 ans.iadd(new Fraction(x, denom));
            }
        }
        return ans;
    }
}

class Fraction {
    long n, d;
    Fraction(long n, long d) {
        long g = gcd(n, d);
        this.n = n / g;
        this.d = d / g;
    }

    public void iadd(Fraction other) {
        long numerator = this.n * other.d + this.d * other.n;
        long denominator = this.d * other.d;
        long g = Fraction.gcd(numerator, denominator);
        this.n = numerator / g;
        this.d = denominator / g;
    }

    static long gcd(long x, long y) {
        return x != 0 ? gcd(y % x, x) : y;
    }
}
```
```python [QFRcSJ8K-Python]
from fractions import Fraction

class Solution(object):
    def isRationalEqual(self, S, T):
        def convert(S):
            if '.' not in S:
                return Fraction(int(S), 1)
            i = S.index('.')
            ans = Fraction(int(S[:i]), 1)
            S = S[i+1:]
            if '(' not in S:
                if S:
                    ans += Fraction(int(S), 10 ** len(S))
                return ans

            i = S.index('(')
            if i:
                ans += Fraction(int(S[:i]), 10 ** i)
            S = S[i+1:-1]
            j = len(S)
            ans += Fraction(int(S), 10**i * (10**j - 1))
            return ans

        return convert(S) == convert(T)
```


**复杂度分析**

* 时间复杂度：$O(1)$，因为字符串 $S, T$ 的长度可以看作是 $O(1)$ 级别的。

* 空间复杂度：$O(1)$。




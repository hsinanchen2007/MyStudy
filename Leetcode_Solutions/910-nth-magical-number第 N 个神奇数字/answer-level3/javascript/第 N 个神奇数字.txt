#### 方法一：数学方法

**思路和算法**

用数学方法找出第 $N$ 个神奇数字。

神奇数字是有规律。设 $L$ 为 $A$，$B$ 的最小公倍数，如果 $X \leq L$ 是神奇数字，那么 $X + L$ 也是神奇数字，因为 $A \| X$， $A \| L$ 可以推出 $A \| (X + L)$，对于 $B$ 也是如此。

有 $M = \frac{L}{A} + \frac{L}{B} - 1$ 个神奇数字小于等于 $L$： 其中 $\frac{L}{A}$ 个是能被 $A$ 整除的，$\frac{L}{B}$ 个能被 $B$ 整除，$1$ 个能同时被 $A，B$ 整除。

设 $N = M*q + r$（$r < M$），前 $L*q$ 个数字有 $M*q$ 个神奇数字，$(L*q + 1, L*q + 2, \cdots)$ 之间有 $r$ 个神奇数字。可以暴力搜 $r$，下一个神奇数字要么是 $L*q + A$ 要么是 $L*q + B$，依此类推。

```java [solution1-Java]
class Solution {
    public int nthMagicalNumber(int N, int A, int B) {
        int MOD = 1_000_000_007;
        int L = A / gcd(A, B) * B;
        int M = L / A + L / B - 1;
        int q = N / M, r = N % M;

        long ans = (long) q * L % MOD;
        if (r == 0)
            return (int) ans;

        int[] heads = new int[]{A, B};
        for (int i = 0; i < r - 1; ++i) {
            if (heads[0] <= heads[1])
                heads[0] += A;
            else
                heads[1] += B;
        }

        ans += Math.min(heads[0], heads[1]);
        return (int) (ans % MOD);
    }

    public int gcd(int x, int y) {
        if (x == 0) return y;
        return gcd(y % x, x);
    }
}
```

```python [solution1-Python]
class Solution(object):
    def nthMagicalNumber(self, N, A, B):
        from fractions import gcd
        MOD = 10**9 + 7

        L = A / gcd(A, B) * B
        M = L / A + L / B - 1
        q, r = divmod(N, M)

        if r == 0:
            return q * L % MOD

        heads = [A, B]
        for _ in xrange(r - 1):
            if heads[0] <= heads[1]:
                heads[0] += A
            else:
                heads[1] += B

        return (q * L + min(heads)) % MOD
```

```c++ [solution1-C++]
class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        int MOD = 1e9 + 7;
        int L = A / gcd(A, B) * B;
        int M = L / A + L / B - 1;
        int q = N / M, r = N % M;

        long ans = (long) q * L % MOD;
        if (r == 0)
            return (int) ans;

        int heads[2] = {A, B};
        for (int i = 0; i < r - 1; ++i) {
            if (heads[0] <= heads[1])
                heads[0] += A;
            else
                heads[1] += B;
        }

        ans += min(heads[0], heads[1]);
        return (int) (ans % MOD);
    }

    int gcd(int x, int y) {
        if (x == 0) return y;
        return gcd(y % x, x);
    }
};
```

```javascript [solution1-Javascript]
var nthMagicalNumber = function(N, A, B) {
    gcd = (x, y) => {
        if (x == 0) return y;
        return gcd(y % x, x);
    }

    const MOD = 1000000007;
    const L = A / gcd(A, B) * B;
    const M = L / A + L / B - 1;
    const q = Math.trunc(N / M), r = N % M;

    let ans = q * L % MOD;
    if (r == 0)
        return ans;

    let heads = [A, B];
    for (let i = 0; i < r - 1; ++i) {
        if (heads[0] <= heads[1])
            heads[0] += A;
        else
            heads[1] += B;
    }

    ans += Math.min(heads[0], heads[1]);
    return ans % MOD;
};
```

**复杂度分析**

* 时间复杂度： $O(A + B)$，数学计算复杂度为 $O(1)$，计算 $q*M$ 后的 $r$ 个神奇数字的复杂度为 $O(M)$，即 $O(A+B)$。

* 空间复杂度： $O(1)$。

#### 方法二： 二分搜索

**思路**

小于等于 $x$ 的神奇数字的个数是一个单调递增函数，可以用二分搜索来做这道题。

**算法**

设 $L = lcm(A, B)$，为 $A$，$B$ 的 **最小公倍数**，$L = \frac{A * B}{gcd(A, B)}$。

$f(x)$ 为小于等于 $x$ 的神奇数字的个数。$f(x) = \lfloor \frac{x}{A} \rfloor + \lfloor \frac{x}{B} \rfloor - \lfloor \frac{x}{L} \rfloor$。有 $\lfloor \frac{x}{A} \rfloor$ 个数字能被 $A$ 整除的，$\lfloor \frac{x}{B} \rfloor$ 个数字能被 $B$ 整除，同时需要减去 $\lfloor \frac{x}{L} \rfloor$ 个能被 $A$，$B$ 整除的数。

```java [solution2-Java]
class Solution {
    public int nthMagicalNumber(int N, int A, int B) {
        int MOD = 1_000_000_007;
        int L = A / gcd(A, B) * B;

        long lo = 0;
        long hi = (long) 1e15;
        while (lo < hi) {
            long mi = lo + (hi - lo) / 2;
            // If there are not enough magic numbers below mi...
            if (mi / A + mi / B - mi / L < N)
                lo = mi + 1;
            else
                hi = mi;
        }

        return (int) (lo % MOD);
    }

    public int gcd(int x, int y) {
        if (x == 0) return y;
        return gcd(y % x, x);
    }
}
```

```python [solution2-Python]
class Solution(object):
    def nthMagicalNumber(self, N, A, B):
        from fractions import gcd
        MOD = 10**9 + 7
        L = A / gcd(A,B) * B

        def magic_below_x(x):
            #How many magical numbers are <= x?
            return x / A + x / B - x / L

        lo = 0
        hi = 10**15
        while lo < hi:
            mi = (lo + hi) / 2
            if magic_below_x(mi) < N:
                lo = mi + 1
            else:
                hi = mi

        return lo % MOD
```

```c++ [solution2-C++]
class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        int MOD = 1e9 + 7;
        int L = A / gcd(A, B) * B;

        long lo = 0;
        long hi = (long) 1e15;
        while (lo < hi) {
            long mi = lo + (hi - lo) / 2;
            // If there are not enough magic numbers below mi...
            if (mi / A + mi / B - mi / L < N)
                lo = mi + 1;
            else
                hi = mi;
        }

        return (int) (lo % MOD);
    }

    int gcd(int x, int y) {
        if (x == 0) return y;
        return gcd(y % x, x);
    }
};
```

```javascript [solution2-Javascript]
var nthMagicalNumber = function(N, A, B) {
    gcd = (x, y) => {
        if (x == 0) return y;
        return gcd(y % x, x);
    }

    const MOD = 1000000007;
    const L = A / gcd(A, B) * B;

    let lo = 0;
    let hi = 1e15;
    while (lo < hi) {
        let mi = lo + Math.trunc((hi - lo) / 2);
        // If there are not enough magic numbers below mi...
        if (Math.trunc(mi/A) + Math.trunc(mi/B) - Math.trunc(mi/L) < N)
            lo = mi + 1;
        else
            hi = mi;
    }

    return lo % MOD;
};
```

**复杂度分析**

* 时间复杂度： $O(\log(N * \max(A, B)))$。

* 空间复杂度： $O(1)$。
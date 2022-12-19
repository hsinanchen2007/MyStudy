#### 方法一：枚举 [超出时间限制]

我们枚举连续正整数的开始值 `start`，并进行累加，直到结果大于等于 `N`。如果结果刚好等于 `N`，我们就找到了一组答案。

例如当 `N = 6` 时，若开始值为 `1`，我们会累加得到 `1 + 2 + 3 = 6`，得到一组答案；若开始值为 `2`，我们会累加得到 `2 + 3 + 4 = 9`，超出了 `6`。以此类推，直到开始值超过 `N`。

这种方法会超出时间限制。

```Java [sol1]
class Solution {
    public int consecutiveNumbersSum(int N) {
        int ans = 0;
        for (int start = 1; start <= N; ++start) {
            int target = N, x = start;
            while (target > 0)
                target -= x++;
            if (target == 0) ans++;
        }
        return ans;
    }
}
```

```Python [sol1]
class Solution(object):
    def consecutiveNumbersSum(self, N):
        ans = 0
        for start in xrange(1, N+1):
            target = N
            while target > 0:
                target -= start
                start += 1
            if target == 0: ans += 1
        return ans
```


**复杂度分析**

* 时间复杂度：$O(N\sqrt{N})$。

* 空间复杂度：$O(1)$。

#### 方法二：简单数学 [超出时间限制]

假设 $k$ 个连续正整数的和为 $N$，即 $N = (x + 1) + (x + 2) + \cdots + (x + k)$，其中 $x \geq 0$，$k \geq 1$。上式经过拆分可以得到 $N = kx + \frac{1}{2}k(k + 1)$，即 $2N = k(2x + k + 1)$。

我们可以枚举 $k$，根据上面的等式，$k$ 的取值范围为 $1 \leq k \leq 2N$。对于每一个 $k$，我们计算出 $x = \frac{1}{2}(\frac{2N}{k} - k - 1)$，如果得到的 $x$ 是一个非负整数，那么我们就找到了一组解。

```Java [sol2]
class Solution {
    public int consecutiveNumbersSum(int N) {
        // 2N = k(2x + k + 1)
        int ans = 0;
        for (int k = 1; k <= 2*N; ++k)
            if (2 * N % k == 0) {
                int y = 2 * N / k - k - 1;
                if (y % 2 == 0 && y >= 0)
                    ans++;
            }
        return ans;
    }
}
```

```Python [sol2]
class Solution(object):
    def consecutiveNumbersSum(self, N):
        # 2N = k(2x + k + 1)
        ans = 0
        for k in xrange(1, 2*N + 1):
            if 2*N % k == 0:
                y = 2 * N / k - k - 1
                if y % 2 == 0 and y >= 0:
                    ans += 1
        return ans
```

**复杂度分析**

* 时间复杂度：$O(N)$。

* 空间复杂度：$O(1)$。


#### 方法三：进阶数学

在 $2N = k(2x + k + 1)$ 中，我们可以发现 $k < 2x + k + 1$，因此有 $k < \sqrt{2N}$，即我们只需要枚举 $1 \leq k \leq \lfloor \sqrt{2N} \rfloor$ 即可，此时通过枚举可以通过本题。

我们还可以继续挖掘一些性质。由于 $k$ 和 $2x + k + 1$ 的奇偶性不同，此时将 $2N$ 写成 $2^\alpha * M$ 的形式，其中 $\alpha$ 为 $2N$ 中因子 $2$ 的个数，$M$ 为一个奇数。对于 $M$ 的一种拆分 $M = a * b, a \leq b$，可以将 $2N$ 分成奇数 $a$ 和偶数 $2^\alpha * b$ 或者奇数 $b$ 和偶数 $2^\alpha * a$，每一种分配方法中，将小的那个数给 $k$，大的那个数给 $2x + k + 1$，就对应了一组解，那么一种拆分方法对应了两组解。如果不限制 $a \leq b$，那么可以看作一种拆分方法对应了一组解。有一种特殊情况是 $a = b$，此时这种拆分方法只对应了一组解，但仍然和之前的对应（一对一）相同。因此，我们只需要求出 $M$ 的拆分方法即可，其中 $M$ 为 $N$ 的最大奇因子。$M$ 的拆分方法等价于 $M$ 的因子个数。

```Java [sol3]
class Solution {
    public int consecutiveNumbersSum(int N) {
        while ((N & 1) == 0) N >>= 1;
        int ans = 1, d = 3;

        while (d * d <= N) {
            int e = 0;
            while (N % d == 0) {
                N /= d;
                e++;
            }
            ans *= e + 1;
            d += 2;
        }

        if (N > 1) ans <<= 1;
        return ans;
    }
}
```

```Python [sol3]
class Solution(object):
    def consecutiveNumbersSum(self, N):
        while N & 1 == 0:
            N >>= 1

        ans = 1    
        d = 3
        while d * d <= N:
            e = 0
            while N % d == 0:
                N /= d
                e += 1
            ans *= e + 1
            d += 2

        if N > 1: ans *= 2
        return ans
```

**复杂度分析**

* 时间复杂度：$O(\sqrt{N})$。

* 空间复杂度：$O(1)$。
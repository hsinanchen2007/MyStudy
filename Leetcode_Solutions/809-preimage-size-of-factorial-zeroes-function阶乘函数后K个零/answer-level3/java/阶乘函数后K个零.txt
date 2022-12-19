#### 方法一：二分查找【通过】

**思路和算法**

令 `zeta(x)` 为 `x!` 末尾零的个数。如果 `x!` 可以分解为素数的乘积，如 $(2^a * 5^b * \cdots )$ 的形式，那么 `x!` 末尾零的个数为 `min(a, b) = b`。

`zeta(x)` 就是 `x` 除以 5 的次数之和，即 `zeta(x)` 等于 $\lfloor \frac{x}{5^1} \rfloor + \lfloor \frac{x}{5^2} \rfloor + \lfloor \frac{x}{5^3} \rfloor + \lfloor \frac{x}{5^4} \rfloor + \cdots$`。 

可以看出，`zeta(x)` 是一个单调递增函数，因此可以使用二分查找求解。

使用二分查找找出满足 `zeta(x) = K` 的最大 `x` 和最小 `x`。由于一定存在 `zeta(5a-1) < zeta(5a) = zeta(5a+1) = zeta(5a+2) = zeta(5a+3) = zeta(5a+4) < zeta(5a+5)`，即如果存在某个 `x` 使得 `zeta(x) = K`，那么一定存在连续 `5` 个数的阶乘末尾零的个数都为 `K`；如果不存在这样的 `x`，那么阶乘末尾零的个数为 `K` 的数字只有 `0` 个。

```java [solution1-Java]
class Solution {
    public int preimageSizeFZF(long K) {
        long lo = K, hi = 10*K + 1;
        while (lo < hi) {
            long mi = lo + (hi - lo) / 2;
            long zmi = zeta(mi);
            if (zmi == K) return 5;
            else if (zmi < K) lo = mi + 1;
            else hi = mi;
        }
        return 0;
    }

    public long zeta(long x) {
        if (x == 0) return 0;
        return x/5 + zeta(x/5);
    }
}
```

```python [solution1-Python]
class Solution(object):
    def preimageSizeFZF(self, K):
        def zeta(x):
            return x/5 + zeta(x/5) if x > 0 else 0

        lo, hi = K, 10*K + 1
        while lo < hi:
            mi = (lo + hi) / 2
            zmi = zeta(mi)
            if zmi == K: return 5
            elif zmi < K: lo = mi + 1
            else: hi = mi

        return 0
```

**复杂度分析**

* 时间复杂度：$O(\log^2 K)$，二分查找的复杂度为  $O(\log K)$，其中每一步计算 `zeta` 的复杂度也为 $O(\log K)$。

* 空间复杂度：$O(\log K)$，`zeta` 递归调用栈的大小。
#### 方法一：素数分解【通过】

**思路**

将所有操作分成以 `copy` 为首的多组，形如 `(copy, paste, ..., paste)`，再使用 `C` 代表 `copy`，`P` 代表 `paste`。例如操作 `CPPCPPPPCP` 可以分为 `[CPP][CPPPP][CP]` 三组。

假设每组的长度为 `g_1, g_2, ...`。完成第一组操作后，字符串有 `g_1` 个 `A`，完成第二组操作后字符串有 `g_1 * g_2` 个 `A`。当完成所有操作时，共有 `g_1 * g_2 * ... * g_n` 个 `'A'`。

我们最终想要 `N = g_1 * g_2 * ... * g_n` 个 `A`。如果 `g_i` 是合数，存在 `g_i = p * q`，那么这组操作可以分解为两组，第一组包含 1 个` C` 和 `p-1` 个 `P`，第二组包含 1 个 `C` 和 `q-1` 个 `P`。

现在证明这种分割方式使用的操作最少。原本需要 `pq` 步操作，分解后需要 `p+q` 步。因为 `p+q <= pq`，等价于 `1 <= (p-1)(q-1)`，当  `p >= 2` 且 `q >= 2` 时上式永远成立。

**算法**

假设 `g_1, g_2, ...` 就是 `N` 的素数分解，则需要的最少操作等于这些素数之和。

```python [solution1-Python]
class Solution(object):
    def minSteps(self, n):
        ans = 0
        d = 2
        while n > 1:
            while n % d == 0:
                ans += d
                n /= d
            d += 1
        return ans
```

```java [solution1-Java]
class Solution {
    public int minSteps(int n) {
        int ans = 0, d = 2;
        while (n > 1) {
            while (n % d == 0) {
                ans += d;
                n /= d;
            }
            d++;
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(\sqrt{N})$，当 `N` 是素数的平方时，需要循环 $O(\sqrt{N})$ 步。

* 空间复杂度：$O(1)$，`ans` 和 `d` 的存储空间。
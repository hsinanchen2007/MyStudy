####  方法一：
**算法：**

从 `L` 到 `R`，我们首先计算该数字转换为二进制有多少个 1。如果数量是 `2, 3, 5, 7, 11, 13, 17, 19`，则我们增加计数。最高是 19 的原因是 $R \leq 10^6 < 2^{20}$。

```python [solution1-Python]
class Solution(object):
    def countPrimeSetBits(self, L, R):
        primes = {2, 3, 5, 7, 11, 13, 17, 19}
        return sum(bin(x).count('1') in primes
                   for x in xrange(L, R+1))
```

```java [solution1-Java]
class Solution {
    public int countPrimeSetBits(int L, int R) {
        int ans = 0;
        for (int x = L; x <= R; ++x)
            if (isSmallPrime(Integer.bitCount(x)))
                ans++;
        return ans;
    }
    public boolean isSmallPrime(int x) {
        return (x == 2 || x == 3 || x == 5 || x == 7 ||
                x == 11 || x == 13 || x == 17 || x == 19);
    }
}
```

**复杂度分析**

* 时间复杂度：$O(D)$，其中 $D = R-L$，指的是所需判断数字的个数。
* 空间复杂度：$O(1)$。
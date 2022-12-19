####  方法一：
- 若是手写计算答案则相对简单，写代码棘手的部分是所涉及的位操作。
- 我们思考一个问题：对于所需的 `n` 个 `ip` 地址，以及从起始 `ip` 地址开始且在范围内的 `ip` 地址，哪些 `CIDR` 块能够表示在范围内的大部分 `ip` 地址？用贪心的思想是可行的，我们可以一直重复这个过程，直到我们包括 `n` 个 `ip` 地址，所以我们应该尽可能的使用一个大的 `CIDR` 块。

**算法：**
- 我们需要将 `ip` 地址转换为长整数，通过一些基本的操作来实现这个功能--具体看代码实现方式。
- 然后，将 `255.0.0.24` 这样的 `ip` 地址转换为 `start`，它以二进制 `00011000` 结尾。如果 `n>=8`，那么我们应该使用整个块 `255.0.0.24/29`。否则，我们只取满足 $2^x>=n$ `x` 的最小值 。
- 在一般情况下啊，我们使用 `n` 和 `start&-start`（`start` 的最低位）的位长度来计算能表示 $2^{32 - \text{mask}}$ 个 `ip` 地址的掩码。然后，我们动态调整 `start` 和 `n`。
- 在 Java 和 C++ 中，我们应该小心使用长整数来表示转换后的 IP 地址，因为该数字可能超过 $2^{31}$。

```Python [ ]
class Solution(object):
    def ipToInt(self, ip):
        ans = 0
        for x in ip.split('.'):
            ans = 256 * ans + int(x)
        return ans

    def intToIP(self, x):
        return ".".join(str((x >> i) % 256)
                        for i in (24, 16, 8, 0))

    def ipToCIDR(self, ip, n):
        start = self.ipToInt(ip)
        ans = []
        while n:
            mask = max(33 - (start & -start).bit_length(),
                       33 - n.bit_length())
            ans.append(self.intToIP(start) + '/' + str(mask))
            start += 1 << (32 - mask)
            n -= 1 << (32 - mask)
        return ans
```

```Java [ ]
class Solution {
    public List<String> ipToCIDR(String ip, int n) {
        long start = ipToLong(ip);
        List<String> ans = new ArrayList();
        while (n > 0) {
            int mask = Math.max(33 - bitLength(Long.lowestOneBit(start)),
                                33 - bitLength(n));
            ans.add(longToIP(start) + "/" + mask);
            start += 1 << (32 - mask);
            n -= 1 << (32 - mask);
        }
        return ans;
    }
    private long ipToLong(String ip) {
        long ans = 0;
        for (String x: ip.split("\\.")) {
            ans = 256 * ans + Integer.valueOf(x);
        }
        return ans;
    }
    private String longToIP(long x) {
        return String.format("%s.%s.%s.%s",
            x >> 24, (x >> 16) % 256, (x >> 8) % 256, x % 256);
    }
    private int bitLength(long x) {
        if (x == 0) return 1;
        int ans = 0;
        while (x > 0) {
            x >>= 1;
            ans++;
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$。其中 $N$ 表示的是 `nums` 的长度
* 空间复杂度：$O(1)$。
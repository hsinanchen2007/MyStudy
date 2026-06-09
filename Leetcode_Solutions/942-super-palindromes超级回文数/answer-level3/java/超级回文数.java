#### 方法 1：数学

**想法**

假设 $P = R^2$ 是超级回文数。

因为 $R$ 是一个回文数，$R$ 的前一半数字决定了两种可能。我们可以美剧这些数字，让 $k$ 为前一半数字，假如 $k = 1234$ 那么 $R = 1234321$ 或者 $R = 12344321$。

注意到 $P < 10^{18}$，$R < (10^{18})^{\frac{1}{2}} = 10^9$，同时 $R = k \| k'$（两串数字连接），其中 $k'$ 是 $k$ 的反序（也有可能截掉了中间数字），所以 $k < 10^5 = \small\text{MAGIC}$，我们的神奇常数。

**算法**

对于每个 $1 \leq k < \small\text{MAGIC}$，构造回文串 $R$ 并且检验 $R^2$ 是否为回文串。

我们需要将奇数和偶数长度分开考虑，这样当长度超出时就可以提前停止循环。

检验一个整数是否为回文数，只需要检查它是否等于它的逆。构造一个整数的逆，可以按位处理。

```Java []
class Solution {
    public int superpalindromesInRange(String sL, String sR) {
        long L = Long.valueOf(sL);
        long R = Long.valueOf(sR);
        int MAGIC = 100000;
        int ans = 0;

        // count odd length;
        for (int k = 1; k < MAGIC; ++k) {
            StringBuilder sb = new StringBuilder(Integer.toString(k));
            for (int i = sb.length() - 2; i >= 0; --i)
                sb.append(sb.charAt(i));
            long v = Long.valueOf(sb.toString());
            v *= v;
            if (v > R) break;
            if (v >= L && isPalindrome(v)) ans++;
        }

        // count even length;
        for (int k = 1; k < MAGIC; ++k) {
            StringBuilder sb = new StringBuilder(Integer.toString(k));
            for (int i = sb.length() - 1; i >= 0; --i)
                sb.append(sb.charAt(i));
            long v = Long.valueOf(sb.toString());
            v *= v;
            if (v > R) break;
            if (v >= L && isPalindrome(v)) ans++;
        }

        return ans;
    }

    public boolean isPalindrome(long x) {
        return x == reverse(x);
    }

    public long reverse(long x) {
        long ans = 0;
        while (x > 0) {
            ans = 10 * ans + x % 10;
            x /= 10;
        }

        return ans;
    }
}
```

```Python []
class Solution(object):
    def superpalindromesInRange(self, L, R):
        L, R = int(L), int(R)
        MAGIC = 100000

        def reverse(x):
            ans = 0
            while x:
                ans = 10 * ans + x % 10
                x /= 10
            return ans

        def is_palindrome(x):
            return x == reverse(x)

        ans = 0

        # count odd length
        for k in xrange(MAGIC):
            s = str(k)  # Eg. s = '1234'
            t = s + s[-2::-1]  # t = '1234321'
            v = int(t) ** 2
            if v > R: break
            if v >= L and is_palindrome(v):
                ans += 1

        # count even length
        for k in xrange(MAGIC):
            s = str(k)  # Eg. s = '1234'
            t = s + s[::-1]  # t = '12344321'
            v = int(t) ** 2
            if v > R: break
            if v >= L and is_palindrome(v):
                ans += 1

        return ans
```

**复杂度分析**

* 时间复杂度：$O(W^{\frac{1}{4}} * \log W)$，其中 $W = 10^{18}$ 是 $R$ 的上界。$\log W$ 是用来检验每个候选数字是否为回文数。
* 空间复杂度：$O(\log W)$，用于构造回文串。
#### 方法一： 遍历回文串

**思路**

假设有一个回文串 $X$，下一个回文串是什么？

每个 $d$ 长度的回文串都有一个 *回文根*，回文根为前 $k = \frac{d+1}{2}$ 个数字。下一个回文串一定是由下一个回文根组成的。 

举个例子，如果 $123$ 是 $12321$ 的回文根，那么下一个回文串 $12421$ 的回文根就是 $124$。

需要注意一个回文根可能对应两个回文串，例如 $123321$，$12321$ 的回文根就都是 $123$。

**算法**

对于每个 *回文根*，找对应的两个回文串（一个奇数长度，一个偶数长度）。对于 $k$ 长度的回文根，会产生长度为 $2*k - 1$ 和 $2*k - 1$ 的回文串。

当检查回文串的时候，需要先检查小的 $2k - 1$ 长度的，这里直接把数字变成字符串来检查是否对称。

至于检查素数，这里用的是常见的 $O(\sqrt{N})$ 复杂度的算法来检查是不是素数，即检查小于 $\sqrt{N}$ 的数中有没有能整除 $N$ 的。

```Java [solution1-Java]
class Solution {
    public int primePalindrome(int N) {
        for (int L = 1; L <= 5; ++L) {
            //Check for odd-length palindromes
            for (int root = (int)Math.pow(10, L - 1); root < (int)Math.pow(10, L); ++root) {
                StringBuilder sb = new StringBuilder(Integer.toString(root));
                for (int k = L-2; k >= 0; --k)
                    sb.append(sb.charAt(k));
                int x = Integer.valueOf(sb.toString());
                if (x >= N && isPrime(x))
                    return x;
                    //If we didn't check for even-length palindromes:
                    //return N <= 11 ? min(x, 11) : x
            }

            //Check for even-length palindromes
            for (int root = (int)Math.pow(10, L - 1); root < (int)Math.pow(10, L); ++root) {
                StringBuilder sb = new StringBuilder(Integer.toString(root));
                for (int k = L-1; k >= 0; --k)
                    sb.append(sb.charAt(k));
                int x = Integer.valueOf(sb.toString());
                if (x >= N && isPrime(x))
                    return x;
            }
        }

        throw null;
    }

    public boolean isPrime(int N) {
        if (N < 2) return false;
        int R = (int) Math.sqrt(N);
        for (int d = 2; d <= R; ++d)
            if (N % d == 0) return false;
        return true;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def primePalindrome(self, N):
        def is_prime(n):
            return n > 1 and all(n%d for d in xrange(2, int(n**.5) + 1))

        for length in xrange(1, 6):
            #Check for odd-length palindromes
            for root in xrange(10**(length - 1), 10**length):
                s = str(root)
                x = int(s + s[-2::-1]) #eg. s = '123' to x = int('12321')
                if x >= N and is_prime(x):
                    return x
                    #If we didn't check for even-length palindromes:
                    #return min(x, 11) if N <= 11 else x

            #Check for even-length palindromes
            for root in xrange(10**(length - 1), 10**length):
                s = str(root)
                x = int(s + s[-1::-1]) #eg. s = '123' to x = int('123321')
                if x >= N and is_prime(x):
                    return x
```

**复杂度分析**

* 时间复杂度： $O(N)$，其中大于最大 `N` 的素数为 `100030001`，这决定了时间复杂度的上限。

* 空间复杂度： $O(\log N)$。

#### 方法二： 数学法

**算法**

遍历所有数字，检查是不是回文串。如果是，检查是不是素数，如果当前数字长度为 8，可以跳过检查，因为不存在 8 长度的素数。

```Java []
class Solution {
    public int primePalindrome(int N) {
        while (true) {
            if (N == reverse(N) && isPrime(N))
                return N;
            N++;
            if (10_000_000 < N && N < 100_000_000)
                N = 100_000_000;
        }
    }

    public boolean isPrime(int N) {
        if (N < 2) return false;
        int R = (int) Math.sqrt(N);
        for (int d = 2; d <= R; ++d)
            if (N % d == 0) return false;
        return true;
    }

    public int reverse(int N) {
        int ans = 0;
        while (N > 0) {
            ans = 10 * ans + (N % 10);
            N /= 10;
        }
        return ans;
    }
}

```

```Python []
class Solution(object):
    def primePalindrome(self, N):
        def is_prime(n):
            return n > 1 and all(n % d for d in xrange(2, int(n**.5) + 1))

        def reverse(x):
            ans = 0
            while x:
                ans = 10 * ans + x % 10
                x /= 10
            return ans

        while True:
            if N == reverse(N) and is_prime(N):
                return N
            N += 1
            if 10**7 < N < 10**8:
                N = 10**8
```


**复杂度分析**

* 时间复杂度： $O(N)$。

* 空间复杂度： $O(1)$。
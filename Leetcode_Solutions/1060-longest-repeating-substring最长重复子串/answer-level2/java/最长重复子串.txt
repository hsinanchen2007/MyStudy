#### 问题拆分

由于数据范围的限制，我们必须找到一个时间复杂度低于 $O(N^2)$ 的方法。

我们可以将原问题拆分为两个子问题，然后在较优的时间复杂度内依次解决它们。

1. 在 `1` 到 `N` 中枚举子串的长度；

2. 对于枚举的长度 `L`，检查字符串中是否有长度为 `L` 的重复子串。

**子问题一：二分查找子串的长度**

我们可以用最简单的穷举法，从 `N - 1` 开始，递减地枚举子串的长度。但我们可以注意到，如果字符串中有长度为 `k` 的重复子串，那么必然也有长度为 `k - 1` 的重复子串（即长度为 `k` 的重复子串的 `k - 1` 长度的前缀）。因此我们可以使用二分查找的方法找到最小的 `k`，使得对于所有的 `j <= k`，字符串中有长度为 `j` 的重复子串。此时的 `k` 即为最终的答案。下图中给出了一个具体的例子。

![pic](https://pic.leetcode-cn.com/Figures/1062/binary.png)

因此通过二分查找，我们用 $O(\log N)$ 的时间复杂度解决了子问题一。下面给出了二分查找的代码。

```Python [sol1]
class Solution:
    def search(self, L: int, n: int, S: str) -> str:
        """
        Search a substring of given length
        that occurs at least 2 times.
        @return start position if the substring exits and -1 otherwise.
        """
        # Subtask 2 : TODO
        
    def longestRepeatingSubstring(self, S: str) -> str:
        n = len(S)
        
        # binary search, L = repeating string length
        left, right = 1, n
        while left <= right:
            L = left + (right - left) // 2
            if self.search(L, n, S) != -1:
                left = L + 1
            else:
                right = L - 1
               
        return left - 1
```

```Java [sol1]
class Solution {
    /*
        Search a substring of given length
        that occurs at least 2 times.
        Return start position if the substring exits and -1 otherwise.
    */
    public int search(int L, int n, String S) {
        // Subtask 2 : TODO
    }

    public int longestRepeatingSubstring(String S) {
        int n = S.length();
        // binary search, L = repeating string length
        int left = 1, right = n;
        int L;
        while (left <= right) {
            L = left + (right - left) / 2;
            if (search(L, n, S) != -1) left = L + 1;
            else right = L - 1;
        }

        return left - 1;
    }
}
```

**子任务二：检查字符串中是否有长度为 L 的子串**

我们可以使用滑动窗口来遍历所有长度为 `L` 的子串，并通过哈希（Hash）的方法判断是否有两个子串相同。使用不同的哈希方法，我们可以得到不同时间复杂度的算法。

1. 我们直接将每个子串放入哈希集合（Hashset）中，由于长度为 `L` 的子串有 `N - L + 1` 个，因此时间复杂度为 $O((N - L)L)$，并且这种方法的空间复杂度非常高，因为 Hashset 中存储的是子串本身。

2. 我们将每个子串先通过语言的内置函数算出哈希值，再放入哈希集合中。时间复杂度同样为 $O((N - L)L)$，但这种方法的空间复杂度较低，因为 Hashset 中存储的是哈希值。

3. 我们使用 Rabin-Karp 算法计算每个子串的哈希值，这种方法可以在 $O(1)$ 的时间内计算出两个相邻子串之间的哈希值变化，因此计算所有子串的哈希值的时间复杂度为 $O(N - L + 1)$。这种方法空间复杂度同样较低。

![pic](https://pic.leetcode-cn.com/Figures/1062/algorithms.png)

我们接下来会依次介绍这三种方法。

#### 方法一：包含子串的哈希集合

这种方法实现起来非常直接：

- 使用滑动窗口来遍历所有长度为 `L` 的子串；
- 检查当前子串是否已经出现在集合中：
  - 如果已经出现，就说明找到了长度为 `L` 的重复子串；
  - 如果没有出现，我们将当前子串加入集合中。

<![1200](https://pic.leetcode-cn.com/Figures/1062/1062_slide_1.png),![1200](https://pic.leetcode-cn.com/Figures/1062/1062_slide_2.png),![1200](https://pic.leetcode-cn.com/Figures/1062/1062_slide_3.png),![1200](https://pic.leetcode-cn.com/Figures/1062/1062_slide_4.png),![1200](https://pic.leetcode-cn.com/Figures/1062/1062_slide_5.png),![1200](https://pic.leetcode-cn.com/Figures/1062/1062_slide_6.png),![1200](https://pic.leetcode-cn.com/Figures/1062/1062_slide_7.png),![1200](https://pic.leetcode-cn.com/Figures/1062/1062_slide_8.png),![1200](https://pic.leetcode-cn.com/Figures/1062/1062_slide_9.png),![1200](https://pic.leetcode-cn.com/Figures/1062/1062_slide_10.png)>

这种方法的缺点也很显然，直接将字符串存储在集合中会占用大量的空间。

```Python [sol2]
class Solution:
    def search(self, L: int, n: int, S: str) -> str:
        """
        Search a substring of given length
        that occurs at least 2 times.
        @return start position if the substring exits and -1 otherwise.
        """
        seen = set()
        for start in range(0, n - L + 1):
            tmp = S[start:start + L]
            if tmp in seen:
                return start
            seen.add(tmp)
        return -1
        
    def longestRepeatingSubstring(self, S: str) -> str:
        n = len(S)
        
        # binary search, L = repeating string length
        left, right = 1, n
        while left <= right:
            L = left + (right - left) // 2
            if self.search(L, n, S) != -1:
                left = L + 1
            else:
                right = L - 1
               
        return left - 1
```

```Java [sol2]
class Solution {
    /*
        Search a substring of given length
        that occurs at least 2 times.
        Return start position if the substring exits and -1 otherwise.
    */
    public int search(int L, int n, String S) {
        HashSet<String> seen = new HashSet();
        String tmp;
        for (int start = 0; start < n - L + 1; ++start) {
            tmp = S.substring(start, start + L);
            if (seen.contains(tmp)) return start;
            seen.add(tmp);
        }
        return -1;
    }

    public int longestRepeatingSubstring(String S) {
        int n = S.length();
        // binary search, L = repeating string length
        int left = 1, right = n;
        int L;
        while (left <= right) {
            L = left + (right - left) / 2;
            if (search(L, n, S) != -1) left = L + 1;
            else right = L - 1;
        }

        return left - 1;
    }
}
```

**复杂度分析**

* 时间复杂度：平均为 $O(N \log N)$，最坏情况下为 $O(N^2)$。二分查找的时间复杂度为 $O(\log N)$，每次检查的时间复杂度为 $O((N - L)L)$，因此总的时间复杂度为 $O(\sum\limits_{L}(N - L)L)$。即在平均情况下，为 $O(N \log N)$，最坏情况下，$L$ 为 $N/2$，可以达到 $O(N^2)$。

* 空间复杂度：$O(N^2)$，为哈希集合占用的空间。

#### 方法二：包含子串哈希值的哈希集合

为了减少方法一中的空间复杂度，我们可以在哈希集合中存储字符串的哈希值，而不是字符串的本身。

![pic](https://pic.leetcode-cn.com/Figures/1062/dupe.png)

```Python [sol3]
class Solution:
    def search(self, L: int, n: int, S: str) -> str:
        """
        Search a substring of given length
        that occurs at least 2 times.
        @return start position if the substring exits and -1 otherwise.
        """
        seen = set()
        for start in range(0, n - L + 1):
            tmp = S[start:start + L]
            h = hash(tmp)
            if h in seen:
                return start
            seen.add(h)
        return -1
        
    def longestRepeatingSubstring(self, S: str) -> str:
        n = len(S)
        
        # binary search, L = repeating string length
        left, right = 1, n
        while left <= right:
            L = left + (right - left) // 2
            if self.search(L, n, S) != -1:
                left = L + 1
            else:
                right = L - 1
               
        return left - 1
```

```Java [sol3]
class Solution {
    /*
        Search a substring of given length
        that occurs at least 2 times.
        Return start position if the substring exits and -1 otherwise.
    */
    public int search(int L, int n, String S) {
        HashSet<Integer> seen = new HashSet();
        String tmp;
        int h;
        for (int start = 0; start < n - L + 1; ++start) {
            tmp = S.substring(start, start + L);
            h = tmp.hashCode();
            if (seen.contains(h)) return start;
            seen.add(h);
        }
        return -1;
    }

    public int longestRepeatingSubstring(String S) {
        int n = S.length();
        // binary search, L = repeating string length
        int left = 1, right = n;
        int L;
        while (left <= right) {
            L = left + (right - left) / 2;
            if (search(L, n, S) != -1) left = L + 1;
            else right = L - 1;
        }

        return left - 1;
    }
}
```

但这种方法并不会减少时间复杂度。

**复杂度分析**

* 时间复杂度：平均为 $O(N \log N)$，最坏情况下为 $O(N^2)$，和方法一相同。

* 空间复杂度：$O(N)$，为哈希集合占用的空间。

#### 方法三：Rabin-Karp 字符串哈希算法

为了能够快速计算出字符串编码，我们可以将字符串看成一个 `26` 进制的数（因为字符串中仅包含小写字母），它对应的十进制的值就是字符串的编码值。首先将字符转换为 `26` 进制中的 `0 - 25`，即通过 `arr[i] = (int)S.charAt(i) - (int)'a'`，可以将字符串 `abcd` 转换为 `[0, 1, 2, 3]`，它对应的 10 进制值为：

$$
h_0 = 0 \times 26^3 + 1 \times 26^2 + 2 \times 26^1 + 3 \times 26^0
$$

我们将这个表达式写得更通用一些，设 $c_i$ 为字符串中第 `i` 个字符对应的数字，$a = 26$ 为字符串的进制，那么有：

$$
\begin{aligned}
h_0 &= c_0 a^{L - 1} + c_1 a^{L - 2} + ... + c_i a^{L - 1 - i} + ... + c_{L - 1} a^1 + c_L a^0\\
&= \sum_{i = 0}^{L - 1}{c_i a^{L - 1 - i}}
\end{aligned}
$$

当我们向右移动滑动窗口时，例如从 `abcd` 变成 `bcde`，此时字符串对应的值从 `[0, 1, 2, 3]` 变成 `[1, 2, 3, 4]`，移除了最高位的 `0`，并且在最低位添加了 `4`，那么我们可以快速地计算出新的字符串的编码：

$$
h_1 = (h_0 - 0 \times 26^3) \times 26 + 4 \times 26^0
$$

更加通用的写法是：

$$
h_1 = (h_0 a - c_0 a^L) + c_{L + 1}
$$

这样，我们只需要 $O(L)$ 的时间复杂度计算出最左侧子串的编码，这个 $O(L)$ 和滑动窗口的循环是独立的。在滑动窗口向右滑动时，计算新的子串的编码的时间复杂度仅为 $O(1)$。

最后一个需要解决的问题是，在实际的编码计算中，$a^L$ 的值可能会非常大，在 C++ 和 Java 语言中，会导致整数的上溢出。一般的解决方法时，对编码值进行取模，将编码控制在一定的范围内，防止溢出，即`h = h % modulus`。根据[生日悖论](https://baike.baidu.com/item/%E7%94%9F%E6%97%A5%E6%82%96%E8%AE%BA)，模数一般需要和被编码的信息数量的平方根的数量级相同，在本题中，相同长度的子串的数量不会超过 $N$ 个，因此选取模数是 $2^{24}$（无符号整型数的最大值）是足够的。在 Java 中可以用如下的代码实现取模：

```Java
h = (h * a - nums[start - 1] * aL % modulus + modulus) % modulus;
h = (h + nums[start + L - 1]) % modulus;
```

而在 Python 中，整型数没有最大值，因此可以在运算的最后再取模：

```Python
h = (h * a - nums[start - 1] * aL + nums[start + L - 1]) % modulus
```

在解决算法题时，我们只要判断两个编码是否相同，就表示它们对应的字符串是否相同。但在实际的应用场景中，会出现字符串不同但编码相同的情况，因此在实际场景中使用 Rabin-Karp 字符串编码时，推荐在编码相同时再对字符串进行比较，防止出现错误。

```Python [sol4]
class Solution:
    def search(self, L: int, a: int, modulus: int, n: int, nums: List[int]) -> str:
        """
        Rabin-Karp with polynomial rolling hash.
        Search a substring of given length
        that occurs at least 2 times.
        @return start position if the substring exits and -1 otherwise.
        """
        # compute the hash of string S[:L]
        h = 0
        for i in range(L):
            h = (h * a + nums[i]) % modulus
              
        # already seen hashes of strings of length L
        seen = {h} 
        # const value to be used often : a**L % modulus
        aL = pow(a, L, modulus) 
        for start in range(1, n - L + 1):
            # compute rolling hash in O(1) time
            h = (h * a - nums[start - 1] * aL + nums[start + L - 1]) % modulus
            if h in seen:
                return start
            seen.add(h)
        return -1
        
    def longestRepeatingSubstring(self, S: str) -> str:
        n = len(S)
        # convert string to array of integers
        # to implement constant time slice
        nums = [ord(S[i]) - ord('a') for i in range(n)]
        # base value for the rolling hash function
        a = 26
        # modulus value for the rolling hash function to avoid overflow
        modulus = 2**24
        
        # binary search, L = repeating string length
        left, right = 1, n
        while left <= right:
            L = left + (right - left) // 2
            if self.search(L, a, modulus, n, nums) != -1:
                left = L + 1
            else:
                right = L - 1
               
        return left - 1
```

```Java [sol4]
class Solution {
    /*
      Rabin-Karp with polynomial rolling hash.
      Search a substring of given length
      that occurs at least 2 times.
      Return start position if the substring exits and -1 otherwise.
    */

    public int search(int L, int a, long modulus, int n, int[] nums) {
        // compute the hash of string S[:L]
        long h = 0;
        for (int i = 0; i < L; ++i) h = (h * a + nums[i]) % modulus;

        // already seen hashes of strings of length L
        HashSet<Long> seen = new HashSet();
        seen.add(h);
        // const value to be used often : a**L % modulus
        long aL = 1;
        for (int i = 1; i <= L; ++i) aL = (aL * a) % modulus;

        for(int start = 1; start < n - L + 1; ++start) {
            // compute rolling hash in O(1) time
            h = (h * a - nums[start - 1] * aL % modulus + modulus) % modulus;
            h = (h + nums[start + L - 1]) % modulus;
            if (seen.contains(h)) return start;
            seen.add(h);
        }
        return -1;
    }

    public int longestRepeatingSubstring(String S) {
        int n = S.length();
        // convert string to array of integers
        // to implement constant time slice
        int[] nums = new int[n];
        for (int i = 0; i < n; ++i) nums[i] = (int)S.charAt(i) - (int)'a';
        // base value for the rolling hash function
        int a = 26;
        // modulus value for the rolling hash function to avoid overflow
        long modulus = (long)Math.pow(2, 24);

        // binary search, L = repeating string length
        int left = 1, right = n;
        int L;
        while (left <= right) {
            L = left + (right - left) / 2;
            if (search(L, a, modulus, n, nums) != -1) left = L + 1;
            else right = L - 1;
        }

        return left - 1;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N \log N)$，二分查找的时间复杂度为 $O(\log N)$，Rabin-Karp 字符串哈希的时间复杂度为 $O(N)$。

* 空间复杂度：$O(N)$，为哈希集合占用的空间。
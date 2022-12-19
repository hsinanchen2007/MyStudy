#### 方法一： 排列组合

**思路**

对 `N` 全排列，对每个排列检查是不是 `2` 的幂。

**算法**

这个方法有两个点： 
1. 如何产生所有的排列组合？
2. 如何检查当前排列是不是 `2` 的幂？

怎么产生所有的排列组合呢？ 把任意数字放在首位(`start = 0`)，接着从剩余数字中任意找一个放在第二个位置(`start = 1`)，依次类推。在 `Python` 实现中，用内置方法 `itertools.permutations` 就可以得到所有的排列组合。

检查一个排列是不是 `2` 的幂，首先需要检查有没有前置 `0`，再不断除 `2` 直到当前数为奇数。如果结果是 `1`，那就是 2 的幂。在 Python 实现中，检查二进制表示是不是只有一个 `1`。

```java [solution1-Java]
class Solution {
    public boolean reorderedPowerOf2(int N) {
        // Build eg. N = 128 -> A = [1, 2, 8]
        String S = Integer.toString(N);
        int[] A = new int[S.length()];
        for (int i = 0; i < S.length(); ++i)
            A[i] = S.charAt(i) - '0';
        return permutations(A, 0);
    }

    // Return true if A represents a valid power of 2
    public boolean isPowerOfTwo(int[] A) {
        if (A[0] == 0) return false;  // no leading zero

        // Build eg. A = [1, 2, 8] -> N = 128
        int N = 0;
        for (int x: A)
            N = 10 * N + x;

        // Remove the largest power of 2
        while (N > 0 && ((N & 1) == 0))
            N >>= 1;

        // Check that there are no other factors besides 2
        return N == 1;
    }

    /**
     * Returns true if some permutation of (A[start], A[start+1], ...)
     * can result in A representing a power of 2.
     */
    public boolean permutations(int[] A, int start) {
        if (start == A.length)
            return isPowerOfTwo(A);

        // Choose some index i from [start, A.length - 1]
        // to be placed into position A[start].
        for (int i = start; i < A.length; ++i) {
            // Place A[start] with value A[i].
            swap(A, start, i);

            // For each such placement of A[start], if a permutation
            // of (A[start+1], A[start+2], ...) can result in A
            // representing a power of 2, return true.
            if (permutations(A, start + 1))
                return true;

            // Restore the array to the state it was in before
            // A[start] was placed with value A[i].
            swap(A, start, i);
        }

        return false;
    }

    public void swap(int[] A, int i, int j) {
        int t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def reorderedPowerOf2(self, N):
        """
        Let's work through an example like N = 128.
        In the last line, 'for cand in itertools.permutations(str(N))' will
        iterate through the six possibilities cand = ('1', '2', '8'),
        cand = ('1', '8', '2'), cand = ('2', '1', '8'), and so on.

        The check cand[0] != '0' is a check that the candidate permutation
        does not have a leading zero.

        The check bin(int("".join(cand))).count('1') == 1 is a check that cand
        represents a power of 2: namely, that the number of ones in its binary
        representation is 1.
        """
        return any(cand[0] != '0' and bin(int("".join(cand))).count('1') == 1
                   for cand in itertools.permutations(str(N)))
```


**复杂度分析**

* 时间复杂度： $O((\log N)! * \log N)$。 注意  $\log N$ 是 $N$ 二进制表示中数字的个数。 对于每个 $N$ 有 $(\log N)!$ 个排列组合，检查是不是 2 的幂时间复杂度为 $O(\log N)$。

* 空间复杂度： $O(\log N)$， `A` 占用的空间。 （Python 中的 `cards`）


#### 方法二： 计数

**思路和算法**

检查两个数的组成数字是不是一样的。举个例子，`338` 和 `833` 的组成数字就是一样的，都有两个 `3` 和一个 `8`。

既然 $N$ 只能是 2 的幂，我们只需要检查 $N$ 跟这些幂是不是拥有一样数字构成。

```java [solution2-Java]
class Solution {
    public boolean reorderedPowerOf2(int N) {
        int[] A = count(N);
        for (int i = 0; i < 31; ++i)
            if (Arrays.equals(A, count(1 << i)))
                return true;
        return false;
    }

    // Returns the count of digits of N
    // Eg. N = 112223334, returns [0,2,3,3,1,0,0,0,0,0]
    public int[] count(int N) {
        int[] ans = new int[10];
        while (N > 0) {
            ans[N % 10]++;
            N /= 10;
        }
        return ans;
    }
}
```

```python [solution2-Python]
class Solution(object):
    def reorderedPowerOf2(self, N):
        count = collections.Counter(str(N))
        return any(count == collections.Counter(str(1 << b))
                   for b in xrange(31))
```

**复杂度分析**

* 时间复杂度： $O(\log^2 N)$。 有 $\log N$ 个候选的 `2` 的幂，每次比较的时间复杂度为 $O(\log N)$。

* 空间复杂度： $O(\log N)$。
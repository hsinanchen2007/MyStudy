#### 方法一：暴力解法【通过】

**思路**

遍历从 `1` 到 `N` 的每个数字 `X`，判断 `X` 是否为好数。

* 如果 `X` 中存在 `3`、`4`、`7` 这样的无效数字，则 `X` 不是一个好数。

* 如果 `X` 中不存在 `2`、`5`、`6`、`9` 这样的旋转后会变成不同的数字，则 `X` 不是一个好数。

* 否则，`X` 可以旋转成一个不同的有效数字。

**算法**

判断数字 `X` 是否为好数，有两种实现方式。最直观的一种方法是把 `X` 转换成字符串然后解析；另一种方法是递归检查 `X` 的最后一位数字。

```java [solution1-Java]
class Solution {
    public int rotatedDigits(int N) {
        // Count how many n in [1, N] are good.
        int ans = 0;
        for (int n = 1; n <= N; ++n)
            if (good(n, false)) ans++;
        return ans;
    }

    // Return true if n is good.
    // The flag is true iff we have an occurrence of 2, 5, 6, 9.
    public boolean good(int n, boolean flag) {
        if (n == 0) return flag;

        int d = n % 10;
        if (d == 3 || d == 4 || d == 7) return false;
        if (d == 0 || d == 1 || d == 8) return good(n / 10, flag);
        return good(n / 10, true);
    }
}
```

```python [solution1-Python]
class Solution(object):
    def rotatedDigits(self, N):
        ans = 0
        # For each x in [1, N], check whether it's good
        for x in xrange(1, N+1):
            S = str(x)
            # Each x has only rotateable digits, and one of them
            # rotates to a different digit
            ans += (all(d not in '347' for d in S)
                    and any(d in '2569' for d in S))
        return ans
```


**复杂度分析**

* 时间复杂度：$O(N \log N)$，检查每个 `X` 的每一位数字。

* 空间复杂度：$O(\log N)$，存储字符串或者 `good` 函数的调用栈。 

#### 方法二：动态规划【通过】

**思路**

根据好数定义，每个好数只能包含数字 `0125689`，并且至少包含 `2569` 中的一个。因此可以逐个写出小于等于 `N` 的所有好数。

这道题目可以使用动态规划解答。状态可以表示为三个变量 `i, equality_flag, involution_flag`。其中 `i` 表示当前正在写第 `i` 位数字；`equality_flag` 表示已经写出的 `j` 位数字是否等于 `N` 的 `j` 位前缀；`involution_flag` 表示从最高位到比当前位高一位的这段前缀中是否含有 `2569` 中的任意一个数字。

`dp(i, equality_flag, involution_flag)` 表示在特定 `equality_flag`，`involution_flag` 的状态下，有多少种从 i 到末尾的后缀能组成一个好数。最终的结果为 `dp(0, True, False)`。

注：数字 `N` 从最高位到最低位的索引，从 0 开始，并依次增大。第 `i` 位表示索引为 `i` 的位置。

**算法**

如果 `equality_flag` 为 true，表示第 `i` 位能取到的最大数字为 `N` 的第 `i` 位对应的数字。并且还需要根据当前状态决定可以写哪些数字。

在代码实现中，我们分别使用了自顶向下的方法和自底向上的方式。Python 代码实现的是自顶向下的方法，从 `for d in xrange(...)` 到 `memo[...] = ans` 这四行代码清晰的说明了状态之间的递归关系。

```java [solution2-Java]
class Solution {
    public int rotatedDigits(int N) {
        char[] A = String.valueOf(N).toCharArray();
        int K = A.length;

        int[][][] memo = new int[K+1][2][2];
        memo[K][0][1] = memo[K][1][1] = 1;
        for (int i = K - 1; i >= 0; --i) {
            for (int eqf = 0; eqf <= 1; ++eqf)
                for (int invf = 0; invf <= 1; ++invf) {
                    // We will compute ans = memo[i][eqf][invf],
                    // the number of good numbers with respect to N = A[i:].
                    // If eqf is true, we must stay below N, otherwise
                    // we can use any digits.
                    // Invf becomes true when we write a 2569, and it
                    // must be true by the end of our writing as all
                    // good numbers have a digit in 2569.
                    int ans = 0;
                    for (char d = '0'; d <= (eqf == 1 ? A[i] : '9'); ++d) {
                        if (d == '3' || d == '4' || d == '7') continue;
                        boolean invo = (d == '2' || d == '5' || d == '6' || d == '9');
                        ans += memo[i+1][d == A[i] ? eqf : 0][invo ? 1 : invf];
                    }
                    memo[i][eqf][invf] = ans;
                }
        }

        return memo[0][1][0];
    }

}
```

```python [solution2-Python]
class Solution(object):
    def rotatedDigits(self, N):
        A = map(int, str(N))

        memo = {}
        def dp(i, equality_flag, involution_flag):
            if i == len(A): return +(involution_flag)
            if (i, equality_flag, involution_flag) not in memo:
                ans = 0
                for d in xrange(A[i] + 1 if equality_flag else 10):
                    if d in {3, 4, 7}: continue
                    ans += dp(i+1, equality_flag and d == A[i],
                              involution_flag or d in {2, 5, 6, 9})
                memo[i, equality_flag, involution_flag] = ans
            return memo[i, equality_flag, involution_flag]

        return dp(0, True, False)
```

**复杂度分析**

* 时间复杂度：$O(\log N)$，在 `N` 的每位数字上计算花费的时间。

* 空间复杂度：$O(\log N)$，`memo` 的存储空间。
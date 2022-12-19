#### 方法一：动态规划(前缀递推)【通过】

**思路**

我们从一个简单的例子开始分析，假设 `T = 'ab'`，当遍历到 `S` 中的 `'b'` 时，这时候只需要知道 `'b'` 之前最近的 `'a'`，就可以找到一个符合条件的窗口 `[i, j]`，其中 `'a' = S[i], ..., S[j] = 'b'`。

这道题有一种比较差的做法是在遍历到 `'b'` 之后再往前遍历找到最近的 `'a'`。但对于 `'abbb...bb'` 这种字符串，这种做法就比较低效了。更好的做法是记住最后一个遇见的 `'a'`，之后每当遍历到 `'b'` 时，就根据之前记住的 `'a'` 来确定窗口。

之前分析的是最简单的例子，如果 `T = 'abc'`，要怎么拓展呢？在遍历到 `S` 中的 `'c'` 时（假设 `S[k] = 'c'`），如果之前已经找到了包含 `'ab'` 的窗口（假设为 `[i, j]`)，那么 `[i, k]` 就是一个包含 `'abc'` 的窗口。

简单来说就是上面描述的这样，先计算包含 `T` 的前缀子串的窗口，再根据前缀子串窗口不断拓展，找到包含整个字符串的窗口。

**算法**

遍历 `T`，维护 `cur` 数组，在遍历到 `T[j]` 时，让 `cur[e] = s`，使其满足 `T[:j]` 为 `S[s: e+1]` 的子序列。在找到包含 `T[:j]` 的窗口的情况下，定义 `new` 来找到包含 `T[:j+1]` 的窗口。

在 Python 实现中，定义的是 `cur` 和 `new` 数组，在 Java 实现中，定义的是 `dp[j]` 和 `dp[~j]` 数组，这两个数组目的是一样的，都是用来保存动态规划最后两行的数据。

最后，遍历所有窗口找到最小窗口作为答案。

```python [solution1-Python]
class Solution(object):
    def minWindow(self, S, T):
        cur = [i if x == T[0] else None
               for i, x in enumerate(S)]
        #At time j when considering T[:j+1],
        #the smallest window [s, e] where S[e] == T[j]
        #is represented by cur[e] = s.
        for j in xrange(1, len(T)):
            last = None
            new = [None] * len(S)
            #Now we would like to calculate the candidate windows
            #"new" for T[:j+1].  'last' is the last window seen.
            for i, u in enumerate(S):
                if last is not None and u == T[j]: new[i] = last
                if cur[i] is not None: last = cur[i]
            cur = new

        #Looking at the window data cur, choose the smallest length
        #window [s, e].
        ans = 0, len(S)
        for e, s in enumerate(cur):
            if s >= 0 and e - s < ans[1] - ans[0]:
                ans = s, e
        return S[ans[0]: ans[1]+1] if ans[1] < len(S) else ""
```

```java [solution1-Java]
class Solution {
    public String minWindow(String S, String T) {
        int[][] dp = new int[2][S.length()];

        for (int i = 0; i < S.length(); ++i)
            dp[0][i] = S.charAt(i) == T.charAt(0) ? i : -1;

        /*At time j when considering T[:j+1],
          the smallest window [s, e] where S[e] == T[j]
          is represented by dp[j & 1][e] = s, and the
          previous information of the smallest window
          [s, e] where S[e] == T[j-1] is stored as
          dp[~j & 1][e] = s.
        */
        for (int j = 1; j < T.length(); ++j) {
            int last = -1;
            Arrays.fill(dp[j & 1], -1);
            //Now we would like to calculate the candidate windows
            //"dp[j & 1]" for T[:j+1].  'last' is the last window seen.
            for (int i = 0; i < S.length(); ++i) {
                if (last >= 0 && S.charAt(i) == T.charAt(j))
                    dp[j & 1][i] = last;
                if (dp[~j & 1][i] >= 0)
                    last = dp[~j & 1][i];
            }
        }

        //Looking at the window data dp[~T.length & 1],
        //choose the smallest length window [s, e].
        int start = 0, end = S.length();
        for (int e = 0; e < S.length(); ++e) {
            int s = dp[~T.length() & 1][e];
            if (s >= 0 && e - s < end - start) {
                start = s;
                end = e;
            }
        }
        return end < S.length() ? S.substring(start, end+1) : "";
    }
}
```

**复杂度分析**

* 时间复杂度：$O(NK)$，其中 $N, k$ 分别为 `S, T` 字符串的长度。

* 空间复杂度：$O(N)$，`dp` 数组长度。

#### 方法二：动态规划(通过 next 数组)【通过】

**思路**

假设窗口的起点为 `S[i]`，`S[i] = T[0]`。那么要拓展窗口就需要在 `S[i+1:]` 中找到最近的 `S[j]`，使得 `S[j] = T[1]`。同样的道理，再从 `S[j+1:]` 中找到最近的 `S[k]`，使得 `S[k] = T[2]`。按照这种方式，就可以找到包含整个 `T` 的窗口。

通过预处理的方式，在常数时间内就可以找到 `S` 中的下一个字符，因此每次猜测的时间复杂度为 $O(K)$，其中 $K$ 为 $T$ 的长度。

**算法**

首先通过预处理的方式计算 `next[i][letter]`，使其表示 `S[i:]` 中第一个出现的 `letter` 的位置，如果不存在则用 `-1` 表示。随后递增 `j`，找到包含 `T[:j]` 的窗口。最终遍历所有窗口，找到其中的最小窗口。

```python [solution2-Python]
class Solution(object):
    def minWindow(self, S, T):
        N = len(S)
        next = [None] * N
        last = [-1] * 26
        for i in xrange(N-1, -1, -1):
            last[ord(S[i]) - ord('a')] = i
            next[i] = tuple(last)

        windows = [[i, i] for i, c in enumerate(S) if c == T[0]]
        for j in xrange(1, len(T)):
            letter_index = ord(T[j]) - ord('a')
            windows = [[root, next[i+1][letter_index]]
                       for root, i in windows
                       if 0 <= i < N-1 and next[i+1][letter_index] >= 0]

        if not windows: return ""
        i, j = min(windows, key = lambda (i, j): j-i)
        return S[i: j+1]
```

```java [solution2-Java]
class Solution {
    public String minWindow(String S, String T) {
        int N = S.length();
        int[] last = new int[26];
        int[][] next = new int[N][26];
        Arrays.fill(last, -1);

        for (int i = N - 1; i >= 0; --i) {
            last[S.charAt(i) - 'a'] = i;
            for (int k = 0; k < 26; ++k) {
                next[i][k] = last[k];
            }
        }

        List<int[]> windows = new ArrayList();
        for (int i = 0; i < N; ++i) {
            if (S.charAt(i) == T.charAt(0))
                windows.add(new int[]{i, i});
        }
        for (int j = 1; j < T.length(); ++j) {
            int letterIndex = T.charAt(j) - 'a';
            for (int[] window: windows) {
                if (window[1] < N-1 && next[window[1]+1][letterIndex] >= 0) {
                    window[1] = next[window[1]+1][letterIndex];
                }
                else {
                    window[0] = window[1] = -1;
                    break;
                }
            }
        }

        int[] ans = {-1, S.length()};
        for (int[] window: windows) {
            if (window[0] == -1) break;
            if (window[1] - window[0] < ans[1] - ans[0]) {
                ans = window;
            }

        }
        return ans[0] >= 0 ? S.substring(ans[0], ans[1] + 1) : "";
    }
}
```

**复杂度分析**

* 空间复杂度：$O(NK)$，其中 $N, K$ 分别为 `S, T` 字符串的长度。

* 空间复杂度：$O(N)$，其为 `windows` 占用空间。
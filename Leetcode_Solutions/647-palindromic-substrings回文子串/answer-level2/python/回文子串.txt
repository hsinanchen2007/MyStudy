#### 方法一：从中心往两侧延伸【通过】 

**思路**

在长度为 `N` 的字符串中，可能的回文串中心位置有 `2N-1` 个：字母，或两个字母中间。

从每一个回文串中心开始统计回文串数量。回文区间 `[a, b]` 表示 `S[a], S[a+1], ..., S[b]` 是回文串，根据回文串定义可知 `[a+1, b-1]` 也是回文区间。

**算法**

对于每个可能的回文串中心位置，尽可能扩大它的回文区间 `[left, right]`。当 `left >= 0 and right < N and S[left] == S[right]` 时，扩大区间。此时回文区间表示的回文串为 `S[left], S[left+1], ..., S[right]`。

```python [solution1-Python]
class Solution(object):
    def countSubstrings(self, S):
        N = len(S)
        ans = 0
        for center in xrange(2*N - 1):
            left = center / 2
            right = left + center % 2
            while left >= 0 and right < N and S[left] == S[right]:
                ans += 1
                left -= 1
                right += 1
        return ans
```

```java [solution1-Java]
class Solution {
    public int countSubstrings(String S) {
        int N = S.length(), ans = 0;
        for (int center = 0; center <= 2*N-1; ++center) {
            int left = center / 2;
            int right = left + center % 2;
            while (left >= 0 && right < N && S.charAt(left) == S.charAt(right)) {
                ans++;
                left--;
                right++;
            }
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N^2)$，其中 $N$ 表示字符串 `S` 的长度，每次扩大回文区间的需要时间 $O(N)$。 

* 空间复杂度：$O(1)$。


#### 方法二：马拉车算法【通过】

**思路**

马拉车算法可以在线性时间内找出以任何位置为中心的最大回文串。

**算法**

假设一个回文串中心为 `center`，该中心对应的最大回文串右边界为 `right`。存在一个 `i` 为当前回文串中心，满足 `i > center`，那么也存在一个 `j` 与 `i` 关于 `center` 对称，可以根据 `Z[i]` 快速计算出 `Z[j]`。

当 `i < right` 时，找出 `i` 关于 `center` 的对称点 `j = 2 * center - i`。此时以 `i` 为中心，半径为 `right - i` 的区间内存在的最大回文串的半径 `Z[i]` 等于 `Z[j]`。

例如，对于字符串 `A = '@#A#B#A#A#B#A#＄'`，当 `center = 7, right = 13, i = 10` 时，`center` 为两个字母 `A` 中间的 `#`，最大回文串右边界为最后一个 `#`，`i` 是最后一个 `B`，`j` 是第一个 `B`。

在 `[center - (right - center), right]` 中，区间中心为 `center`，右边界为 `right`，`i` 和 `j` 关于 `center` 对称，且 `Z[j] = 3`，可以快速计算出 `Z[i] = min(right - i, Z[j]) = 3`。

在 while 循环中，只有当 `Z[i]` 超过 `right - i` 时，才需要逐个比较字符。这种情况下，`Z[i]` 每增加 `1`，`right` 也会增加 `1`，且最多能够增加 `2*N+2` 次。因此这个过程是线性的。

最后，对 `Z` 中每一项 `v` 计算 `(v+1) / 2`，然后求和。假设给定最大回文串中心为 `C`，半径为 `R`，那么以 `C` 为中心，半径为 `R-1, R-2, ..., 0` 的子串也都是回文串。例如 `abcdedcba` 是以 `e` 为中心，半径为 4 的回文串，那么 `e`，`ded`，`cdedc`，`bcdedcb` 和 `abcdedcba` 也都是回文串。

除以 2 是因为实际回文串的半径为 `v` 的一半。例如回文串 `a#b#c#d#e#d#c#b#a` 的半径为实际原回文串半径的 2 倍。

```python [solution2-Python]
def countSubstrings(self, S):
    def manachers(S):
        A = '@#' + '#'.join(S) + '#$'
        Z = [0] * len(A)
        center = right = 0
        for i in xrange(1, len(A) - 1):
            if i < right:
                Z[i] = min(right - i, Z[2 * center - i])
            while A[i + Z[i] + 1] == A[i - Z[i] - 1]:
                Z[i] += 1
            if i + Z[i] > right:
                center, right = i, i + Z[i]
        return Z

    return sum((v+1)/2 for v in manachers(S))
```

```java [solution2-Java]
class Solution {
    public int countSubstrings(String S) {
        char[] A = new char[2 * S.length() + 3];
        A[0] = '@';
        A[1] = '#';
        A[A.length - 1] = '$';
        int t = 2;
        for (char c: S.toCharArray()) {
            A[t++] = c;
            A[t++] = '#';
        }

        int[] Z = new int[A.length];
        int center = 0, right = 0;
        for (int i = 1; i < Z.length - 1; ++i) {
            if (i < right)
                Z[i] = Math.min(right - i, Z[2 * center - i]);
            while (A[i + Z[i] + 1] == A[i - Z[i] - 1])
                Z[i]++;
            if (i + Z[i] > right) {
                center = i;
                right = i + Z[i];
            }
        }
        int ans = 0;
        for (int v: Z) ans += (v + 1) / 2;
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `S` 的长度。根据上面分析，复杂度是线性的。

* 空间复杂度：$O(N)$，数组 `A` 和 `Z` 的大小。
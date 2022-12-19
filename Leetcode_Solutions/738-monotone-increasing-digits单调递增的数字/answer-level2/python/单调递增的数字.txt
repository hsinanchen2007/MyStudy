####  方法一：贪心算法
让我们一个数字一个数字地构造答案。

**算法：**
- 对于 `N` 的每一位数字，我们构建答案 `ans` 的下一位数字。我们找到数字 `d`，其中 `d` 满足 `ans + (d repeating) > N`（按字符串比较）且 `d-1` 满足 `ans + (d-1 repeating) <= N`，因此我们将 `d-1` 添加到我们的答案中。如果找不到这样一个数字 `d`，则在答案中添加 `9`。

```Python [ ]
class Solution(object):
    def monotoneIncreasingDigits(self, N):
        digits = []
        A = map(int, str(N))
        for i in xrange(len(A)):
            for d in xrange(1, 10):
                if digits + [d] * (len(A)-i) > A:
                    digits.append(d-1)
                    break
            else:
                digits.append(9)

        return int("".join(map(str, digits)))
```

```Java [ ]
class Solution {
    public int monotoneIncreasingDigits(int N) {
        String S = String.valueOf(N);
        String ans = "";
        search: for (int i = 0; i < S.length(); ++i) {
            for (char d = '1'; d <= '9'; ++d) {
                if (S.compareTo(ans + repeat(d, S.length() - i)) < 0) {
                    ans += (char) (d - 1);
                    continue search;
                }
            }
            ans += '9';
        }
        return Integer.parseInt(ans);
    }

    public String repeat(char c, int count) {
        StringBuilder sb = new StringBuilder(count);
        for (int i = 0; i < count; ++i) sb.append(c);
        return sb.toString();
    }
}
```

**复杂度分析**

* 时间复杂度：$O(D^2)$。其中 $D \approx \log N$，$N$ 是数字的长度，我们花费 $O(D)$ 的时间构建数字和 $O(D)$ 的时间比较每个候选答案。
* 空间复杂度：$O(D)$，答案和临时字符串的大小。


####  方法二：
- 首先想到的是，我们总是可以得到一个 `d999...9 ` 的候选答案（其中 `0 <= d <= 9` 后接一些数字9）。例如，如果 `n=432543654`，我们总是可以得到至少 `39999999` 的答案。
- 我们可以进行优化。例如，当数字是 `123454321` 时，我们可以有一个 `123449999` 的候选候选答案。这似乎是一个不错的策略，就是采用一个单调递增的前缀，然后在相邻的数字首次下降的索引之前（悬崖）减少这个数字，然后用 `9` 代替其余的字符。
- 这种策略什么时候会出错？如果 `n=333222`，那么我们的策略将给出 `332999` 的候选答案，但这不是单调递增的。
- 因此，我们可以修复我们的策略，通过线性扫描成功地变形成最终的答案 `332999->329999->299999`。

**算法：**
- 我们会找到第一个悬崖 `s[i-1]>s[i]`。然后，当悬崖存在时，我们将减去适当的数字，然后移动 `i`。再把剩下的数字补上 `9`，最后完成扫描。
- 我们可以证明我们的算法是正确的，因为我们每次遇到悬崖时，减少的数字必须至少减少 1。然后，对其余数字的最大的可能选择是全部为 9。

```Python [ ]
class Solution(object):
    def monotoneIncreasingDigits(self, N):
        S = list(str(N))
        i = 1
        while i < len(S) and S[i-1] <= S[i]:
            i += 1
        while 0 < i < len(S) and S[i-1] > S[i]:
            S[i-1] = str(int(S[i-1]) - 1)
            i -= 1
        S[i+1:] = '9' * (len(S) - i-1)
        return int("".join(S))
```

```Java [ ]
class Solution {
    public int monotoneIncreasingDigits(int N) {
        char[] S = String.valueOf(N).toCharArray();
        int i = 1;
        while (i < S.length && S[i-1] <= S[i]) i++;
        while (0 < i && i < S.length && S[i-1] > S[i]) S[--i]--;
        for (int j = i+1; j < S.length; ++j) S[j] = '9';

        return Integer.parseInt(String.valueOf(S));
    }
}
```

**复杂度分析**

* 时间复杂度：$O(D)$。其中 $D \approx \log N$，$N$ 是数字的长度。
* 空间复杂度：$O(D)$，答案所使用的空间。
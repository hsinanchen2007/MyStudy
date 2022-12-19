#### 枚举：

我们枚举 `dict` 中的每一个单词 `word`，并枚举 `s` 中的位置 `i`，如果 `s[i]` 以 `word` 为前缀，那么我们就在 `s` 中找到了一个 `word` 出现的位置。我们把 `word` 占有的所有位置都打上标记，`mask[i] == true` 表示 `s` 的位置 `i` 被打上标记。

在打完所有的标记后，我们得到了 `mask` 数组，接下来我们要用这个数组得到加粗的字符串。对于 `s` 中的位置 `i`，如果 `i == 0`（字符串的起始位置）或者 `mask[i] == true && mask[i - 1] == false`，那么 `i` 就是加粗标签的开始位置；如果 `i == N - 1` 或者 `mask[i] == true && mask[i + 1] == false`，那么 `i` 就是加粗标签的结束位置。在我们找到了所有的开始和结束位置之后，在这些位置插入 `<b>` 和 `</b>` 标签，就得到了加粗的字符串。

```Python [sol1]
class Solution(object):
    def boldWords(self, S, words):
        N = len(S)
        mask = [False] * N
        for i in xrange(N):
            prefix = S[i:]
            for word in words:
                if prefix.startswith(word):
                    for j in xrange(i, min(i+len(word), N)):
                        mask[j] = True

        ans = []
        for incl, grp in itertools.groupby(zip(S, mask), lambda z: z[1]):
            if incl: ans.append("<b>")
            ans.append("".join(z[0] for z in grp))
            if incl: ans.append("</b>")
        return "".join(ans)
```

```Java [sol1]
class Solution {
    public String boldWords(String S, String[] words) {
        int N = S.length();
        boolean[] mask = new boolean[N];
        for (int i = 0; i < N; ++i)
            for (String word: words) search: {
                for (int k = 0; k < word.length(); ++k)
                    if (k+i >= S.length() || S.charAt(k+i) != word.charAt(k))
                        break search;

                for (int j = i; j < i+word.length(); ++j)
                    mask[j] = true;
            }

        StringBuilder ans = new StringBuilder();
        int anchor = 0;
        for (int i = 0; i < N; ++i) {
            if (mask[i] && (i == 0 || !mask[i-1]))
                ans.append("<b>");
            ans.append(S.charAt(i));
            if (mask[i] && (i == N-1 || !mask[i+1]))
                ans.append("</b>");
        }
        return ans.toString();
    }

    public boolean match(String S, int i, int j, String T) {
        for (int k = i; k < j; ++k)
            if (k >= S.length() || S.charAt(k) != T.charAt(k-i))
                return false;
        return true;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N * \sum w_i)$，其中 $N$ 是字符串 `S` 的长度，$\sum w_i$ 是 `dict` 中所有单词的长度之和。

* 空间复杂度：$O(N)$。
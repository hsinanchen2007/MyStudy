**方法一：递归**

对于单词表 `words` 中的每个单词，我们都可以选择拼写或者不拼写。因此我们可以使用递归的方法枚举出所有拼写单词的情况。

我们从 `words` 中的第一个单词开始，并维护 `cur_letters` 表示当前可以使用的字母。对于第一个单词，如果它可以用 `cur_letters` 中的字母进行拼写，我们可以从 `cur_letters` 中扣除需要使用的字母，并递归地搜索第二个单词。同样我们可以选择不拼写第一个单词，那么 `cur_letters` 不会有任何变化，直接递归地搜索第二个单词。

我们还需要计算出每种情况下的得分。假设在递归时，函数 `dfs(i, cur_letters)` 会返回从 `words` 中的第 `i` 个单词开始，并且当前可以使用的字母为 `cur_letters` 时的最大得分，那么根据上述的两种递归的情况，如果我们选择拼写第 `i` 个单词，那么得分为 `dfs(i + 1, cur_letters - letters[i]) + score[i]`；如果我们选择不拼写第 `i` 个单词，那么得分为 `dfs(i + 1, cur_letters)`。这两者的最大值即为最大得分，并作为 `dfs(i, cur_letters)` 的返回值。

```Python [sol1]
class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        def dfs(i, n, cur_letters):
            if i == n:
                return 0

            ret = dfs(i + 1, n, cur_letters)
            ith_letter = collections.Counter(words[i])
            check = all(cur_letters[k] >= v for k, v in ith_letter.items())
            if check:
                ith_score = sum(score[ord(k) - 97] * v for k, v in ith_letter.items())
                cur_letters -= ith_letter
                ret = max(ret, ith_score + dfs(i + 1, n, cur_letters))
                cur_letters += ith_letter
            return ret

        n = len(words)
        c_letters = collections.Counter(letters)
        return dfs(0, n, c_letters)
```

**复杂度分析**

- 时间复杂度：$O(2^N*L)$，其中 $N$ 是数组 `words` 的长度，$L$ 是单词的长度最大值。

- 空间复杂度：$O(N)$，递归的层数最多为 $N$，在每一层递归中，我们只会使用常数的空间。
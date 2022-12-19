#### 方法一：模拟

我们介绍两种不同的模拟方法。在这两种方法中，我们都通过最初给定的字符串 `S` 和替换操作，找出其中无效的那些，并保留有效的，以此得到最终的答案 `ans`。

在 `Java` 的代码中，我们根据替换操作得到数组 `match`，其中 `match[ix] = j` 表示字符串 `S` 从第 `ix` 位开始和 `sources[j]` 匹配，并且会被替换成 `target[j]`，也就是说 `sources[j]` 是字符串 `S[ix:]` 的前缀。在得到 `match` 数组后，我们对 `S` 从左到右进行扫描，对于每个位置 `ix`，如果 `match[ix]` 有值 `j`，那么在 `ans` 尾部添加字符串 `targets[j]`，并将 `ix` 增加 `sources[j].length()`；否则在 `ans` 尾部添加字符 `S[ix]`，并将 `ix` 增加 `1`。

在 `Python` 代码中，我们将所有的替换操作根据 `indexes` 值进行降序排序，这样我们依次执行替换操作时，前面的替换操作并不会改变后面替换操作的 `indexes` 值的位置。对于每个替换操作 `i`，我们直接判断 `S` 中对应的子串是否和 `sources[i]` 相等，如果相等，则替换为 `targets[i]`。

```Java [sol1]
class Solution {
    public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
        int N = S.length();
        int[] match = new int[N];
        Arrays.fill(match, -1);

        for (int i = 0; i < indexes.length; ++i) {
            int ix = indexes[i];
            if (S.substring(ix, ix + sources[i].length()).equals(sources[i]))
                match[ix] = i;
        }

        StringBuilder ans = new StringBuilder();
        int ix = 0;
        while (ix < N) {
            if (match[ix] >= 0) {
                ans.append(targets[match[ix]]);
                ix += sources[match[ix]].length();
            } else {
                ans.append(S.charAt(ix++));
            }
        }
        return ans.toString();
    }
}
```

```Python [sol1]
class Solution(object):
    def findReplaceString(self, S, indexes, sources, targets):
        S = list(S)
        for i, x, y in sorted(zip(indexes, sources, targets), reverse = True):
            if all(i+k < len(S) and S[i+k] == x[k] for k in xrange(len(x))):
                S[i:i+len(x)] = list(y)

        return "".join(S)
```

**复杂度分析**

* 时间复杂度：$O(NQ)$，其中 $N$ 是字符串 `S` 的长度，$Q$ 是替换操作的数量。

* 空间复杂度：$O(N)$，我们认为 `sources` 和 `targets` 中的字符串长度均为常数。
#### 方法 1：将 B 合并成一个单词

**想法**

如果 `b` 是 `a` 的子集，那么就称 `a` 是 `b` 的超集。记录 $N_{\text{"a"}}(\text{word})$ 是 word 中字母 $\text{"a"}$ 出现次数。

当我们检查 `A` 中的单词 `wordA` 是否是 `wordB` 的超集时，我们只需要单独检验每个字母个数：对于每个字母，有 $N_{\text{letter}}(\text{wordA}) \geq N_{\text{letter}}(\text{wordB})$。

现在，检验单词 `wordA` 是否是所有 $\text{wordB}_i$ 的超集，我们需要检验所有 $i$ 是否满足 $N_{\text{letter}}(\text{wordA}) \geq N_{\text{letter}}(\text{wordB}_i)$，等价于检验 $N_{\text{letter}}(\text{wordA}) \geq \max\limits_i(N_{\text{letter}}(\text{wordB}_i))$。

例如，当我们检验 `"warrior"` 是否是 `B = ["wrr", "wa", "or"]` 的超集时，我们可以按照字母出现的最多次数将 `B` 中所有单词合并成一个单词 `"arrow"`，然后判断一次即可。

**算法**

将 `B` 合并成一个单独的单词 `bmax`，然后比较 `A` 中的所有单词 `a`。

```Java []
class Solution {
    public List<String> wordSubsets(String[] A, String[] B) {
        int[] bmax = count("");
        for (String b: B) {
            int[] bCount = count(b);
            for (int i = 0; i < 26; ++i)
                bmax[i] = Math.max(bmax[i], bCount[i]);
        }

        List<String> ans = new ArrayList();
        search: for (String a: A) {
            int[] aCount = count(a);
            for (int i = 0; i < 26; ++i)
                if (aCount[i] < bmax[i])
                    continue search;
            ans.add(a);
        }

        return ans;
    }

    public int[] count(String S) {
        int[] ans = new int[26];
        for (char c: S.toCharArray())
            ans[c - 'a']++;
        return ans;
    }
}
```

```Python []
class Solution(object):
    def wordSubsets(self, A, B):
        def count(word):
            ans = [0] * 26
            for letter in word:
                ans[ord(letter) - ord('a')] += 1
            return ans

        bmax = [0] * 26
        for b in B:
            for i, c in enumerate(count(b)):
                bmax[i] = max(bmax[i], c)

        ans = []
        for a in A:
            if all(x >= y for x, y in zip(count(a), bmax)):
                ans.append(a)
        return ans
```

**复杂度分析**

* 时间复杂度：$O(A+B)$，其中 $A$ 和 $B$ 分别是 `A` 和 `B` 的单词个数。
* 空间复杂度：$O(A\text{.length} + B\text{.length})$。
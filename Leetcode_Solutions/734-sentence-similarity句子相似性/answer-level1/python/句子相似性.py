####  方法：Set [Accepted]
**算法：**
- 判断 `words1[i]` 和 `words2[i]` 是否相似，可以是同一个单词，或者 `(words1[i], words2[i])` 或 `(words2[i], words1[i])` 在相似单词对 `pairs` 中。              
- 为了检查 `(words1[i], words2[i])` 在相似单词对中 `pairs` 是否存在，我们可以将所有单词对放入集合 `Set` 结构中。

```Python [ ]
class Solution(object):
    def areSentencesSimilar(self, words1, words2, pairs):
        if len(words1) != len(words2): return False

        pairset = set(map(tuple, pairs))
        return all(w1 == w2 or (w1, w2) in pairset or (w2, w1) in pairset
                   for w1, w2 in zip(words1, words2))
```

```Java [ ]
class Solution {
    public boolean areSentencesSimilar(
            String[] words1, String[] words2, String[][] pairs) {
        if (words1.length != words2.length) return false;

        Set<String> pairset = new HashSet();
        for (String[] pair: pairs)
            pairset.add(pair[0] + "#" + pair[1]);

        for (int i = 0; i < words1.length; ++i) {
            if (!words1[i].equals(words2[i]) &&
                    !pairset.contains(words1[i] + "#" + words2[i]) &&
                    !pairset.contains(words2[i] + "#" + words1[i]))
                return false;
        }
        return true;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N+P)$。其中 $N$ 是 `words1` 的长度和 `words2` 的长度的最大值，$P$ 单词对的长度。
* 空间复杂度：$O(P)$，集合 `Set` 中需要存放 $P$ 个单词对。
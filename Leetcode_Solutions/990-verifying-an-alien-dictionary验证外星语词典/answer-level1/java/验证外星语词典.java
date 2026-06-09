#### 方法一： 检查相邻单词

**思路**

只有每对相邻单词都是有序的，那么整个 `words` 才是有序的。因为有序性是可以传递的，例如，`a <= b` 和 `b <= c` 可以推出 `a <= c`。

**算法**

检查相邻单词 `a` 和 `b` 是否满足 `a <= b`。

为了检查相邻单词 `a`，`b` 是否满足 `a <= b`，只需要检查它们第一个不同的字母就可以了。例如，对于`"applying"` 和 `"apples"`，第一个不同的字母是 `y` 和 `e`。之后只需要比较这两个字母在 `order` 中的下标就可以了。 

还需要考虑两个单词长度不等的情况。例如，当比较 `"app"` 和 `"apply"` 的时候，前三个字母都是相等的，但 `"app"` 比 `"apply"` 更短，所以满足 `a <= b`。

```java [solution1-Java]
class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        int[] index = new int[26];
        for (int i = 0; i < order.length(); ++i)
            index[order.charAt(i) - 'a'] = i;

        search: for (int i = 0; i < words.length - 1; ++i) {
            String word1 = words[i];
            String word2 = words[i+1];

            // Find the first difference word1[k] != word2[k].
            for (int k = 0; k < Math.min(word1.length(), word2.length()); ++k) {
                if (word1.charAt(k) != word2.charAt(k)) {
                    // If they compare badly, it's not sorted.
                    if (index[word1.charAt(k) - 'a'] > index[word2.charAt(k) - 'a'])
                        return false;
                    continue search;
                }
            }

            // If we didn't find a first difference, the
            // words are like ("app", "apple").
            if (word1.length() > word2.length())
                return false;
        }

        return true;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def isAlienSorted(self, words, order):
        order_index = {c: i for i, c in enumerate(order)}

        for i in xrange(len(words) - 1):
            word1 = words[i]
            word2 = words[i+1]

            # Find the first difference word1[k] != word2[k].
            for k in xrange(min(len(word1), len(word2))):
                # If they compare badly, it's not sorted.
                if word1[k] != word2[k]:
                    if order_index[word1[k]] > order_index[word2[k]]:
                        return False
                    break
            else:
                # If we didn't find a first difference, the
                # words are like ("app", "apple").
                if len(word1) > len(word2):
                    return False

        return True
```


**复杂度分析**

* 时间复杂度： $O(C)$，其中 $C$ 是 `words` 中单词总长度和。

* 空间复杂度： $O(1)$。
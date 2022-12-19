### 解题思路
１．排序，长度递减
２．判断是否为新词＋１


### 代码

```python3
class Trie:
    def __init__(self):
        self.children = {}
        self.end = False
        self.count = 0

    def _insert(self, word):
        root = self
        is_new = False
        for c in word:
            if c not in root.children:
                is_new = True
                root.children[c] = Trie()

            root = root.children[c]
        root.end = True

        root.count = len(word) + 1 if is_new else 0
        return root.count
        pass


class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        root = Trie()
        words.sort(key=lambda x: len(x), reverse=True)
        count = 0
        for word in words:
            count += root._insert(word[::-1])

        return count
```
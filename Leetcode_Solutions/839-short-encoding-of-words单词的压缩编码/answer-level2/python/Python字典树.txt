```python
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        # 定义字典树
        class Trie:
            def __init__(self):
                self.lookup = {}

            def find_or_create(self, word):
                # 返回是找到了单词还是创建了单词
                created = False
                lookup = self.lookup
                for w in word:
                    if w not in lookup:
                        # 这是一个新单词
                        created = True
                        lookup[w] = {}
                    lookup = lookup[w]
                return created

        result = 0
        trie = Trie()
        # 由于需要求一个词是否另一个词的后缀，需要从长到短插入逆序的单词
        words.sort(key=lambda s:len(s), reverse=True)
        for word in words:
            if trie.find_or_create(word[::-1]):
                # 创建了单词
                result += len(word) + 1
        return result
```
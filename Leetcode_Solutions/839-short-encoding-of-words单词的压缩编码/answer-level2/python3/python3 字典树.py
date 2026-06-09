标准的字典树应用，直接套模板即可，将每个单词反转，然后按照单词长度从长到短排序。然后对列表进行遍历，依次判断字典树中是否存在该前缀，不存在则插入字典树
```
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        l = 0
        self.root = {}
        self.end_of_word = '#'
        words = sorted([x[:: -1] for x in set(words)], key=lambda i: len(i), reverse=True)
        for w in words:
            if not self.startsWith(w):
                self.insert(w)
                l = l + len(w) + 1
        return l

    def insert(self, word: str) -> None:
        node = self.root
        for char in word:
            node = node.setdefault(char, {})
        node[self.end_of_word] = self.end_of_word

    def startsWith(self, prefix: str) -> bool:
        node = self.root
        for char in prefix:
            if char not in node:
                return False
            node = node[char]
        return True
```

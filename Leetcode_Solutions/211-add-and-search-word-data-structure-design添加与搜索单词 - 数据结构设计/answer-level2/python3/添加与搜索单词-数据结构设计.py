### 解题思路
利用前缀树存储单词；

利用深度优先搜索单词，即遇见字符`.`，遍历当前节点的所有边进行搜索；

### 代码

```python3
class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.trie = {}

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        root = self.trie
        for i in range(len(word)):
            if word[i] not in root:
                root[word[i]] = {}
            root = root[word[i]]
        root['#'] = '#'

    def _search(self, word, i, root):
        if i == len(word):
            return True if '#' in root else False
        
        for j in range(i, len(word)):
            if word[j] == '.':
                for char in root.keys():
                    if char != '#' and self._search(word, j+1, root[char]):
                        return True
                return False
            else:
                if word[j] not in root:
                    return False
            root = root[word[j]]
        return True if '#' in root else False
    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        return self._search(word, 0, self.trie)

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
```
### 解题思路

知识点：前缀树

### 代码

```python
class TrieNode(object):

    def __init__(self):
        self.data = {}
        self.is_end = False

class WordDictionary(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: None
        """
        node = self.root
        for ch in word:
            if ch not in node.data:
                node.data[ch] = TrieNode()

            node = node.data[ch]

        node.is_end = True

    def search_helper(self, word, start, node):
        if start == len(word):
            return node.is_end

        if word[start] == '.':
            for ch in node.data:
                if self.search_helper(word, start+1, node.data[ch]):
                    return True

        elif word[start] in node.data:
            return self.search_helper(word, start+1, node.data[word[start]])

        return False

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        return self.search_helper(word, 0, self.root)
```
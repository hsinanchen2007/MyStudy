### 解题思路
1、所谓的字典树就是递归的以每个字符嵌套结构
2、以每个字符创建嵌套的字典，如果不存在就递归创建；

### 代码

```python
class Trie(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = {}

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: None
        """
        node = self.root
        for s in word:
            if s not in node:
                node[s] = {}

            node = node[s]
        node["is_word"] = True

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        node = self.root
        for s in word:
            if s in node:
                node = node[s]
            else:
                return False
        return "is_word" in node and node["is_word"]

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        node = self.root
        for s in prefix:
            if s in node:
                node = node[s]
            else:
                return False
        return True

```
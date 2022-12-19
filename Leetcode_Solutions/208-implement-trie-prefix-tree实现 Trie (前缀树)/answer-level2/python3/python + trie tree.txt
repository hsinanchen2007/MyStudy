```python
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.trie = {}
        

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        dic = self.trie
        for w in word:
            if w not in dic:
                dic[w] = {}
            dic = dic[w]
        dic['trim'] = True
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        dic = self.trie
        for w in word:
            if w not in dic: return False
            dic = dic[w]
        return 'trim' in dic
        

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        dic = self.trie
        for w in prefix:
            if w not in dic: return False
            dic = dic[w]
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
```
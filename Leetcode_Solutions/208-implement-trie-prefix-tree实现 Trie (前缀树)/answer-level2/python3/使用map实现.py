```
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.m = {}

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        n = self.m
        for i in word:
            if i not in n:
                n[i] = {}
            n = n[i]
        n['leaf'] = True           
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        n = self.m
        for i in word:
            if i not in n:
                return False
            n = n[i]
        return n.get('leaf', False)           

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        n = self.m
        for i in prefix:
            if i not in n:
                return False
            n = n[i]
        return True          
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
```

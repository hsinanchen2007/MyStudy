### 解题思路
產生一個list 再依序檢查
### 代码

```python3
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.vec = []


    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        self.vec.append(word)


    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        if word in self.vec:
            return True
        else:
            return False    



    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        for w in self.vec:
            if w[:len(prefix)] == prefix:
                return True
        return False


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
```
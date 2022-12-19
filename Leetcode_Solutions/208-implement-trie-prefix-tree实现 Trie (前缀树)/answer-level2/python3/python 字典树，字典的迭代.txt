### 解题思路
此处撰写解题思路
apple:{'a': {'p': {'p': {'l': {'e': {'end': True}}}}}}             #第一次insert，最后一个'e'存在结束'end'
app:  {'a': {'p': {'p': {'l': {'e': {'end': True}}, 'end': True}}}}#第二次insert，第二个'p'存在结束'end'

### 代码

```python3

class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = {}

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        cu = self.root
        for i in word:
            if i not in cu:
                cu[i]={}
            cu = cu[i]
        cu['end'] = True


    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        
        cu = self.root
        for i in word:
            if i not in cu:
                return False
            cu = cu[i]
        
        return 'end' in cu

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        cu = self.root
        for i in prefix:
            if i not in cu:
                return False
            cu = cu[i]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
```
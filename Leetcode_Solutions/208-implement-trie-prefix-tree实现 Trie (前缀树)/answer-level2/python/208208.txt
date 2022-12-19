### 解题思路
此处撰写解题思路

### 代码

```python3
from collections import defaultdict
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = defaultdict(list)#根节点

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        if word:
            self.root[len(word)].append(word)

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        if not word:return False
        return word in self.root[len(word)]

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        if not prefix:return False
        alen=len(prefix)
        maxnum= max(self.root.keys()) if self.root.keys() else 0
        for pres in range(alen,maxnum+1):
                #print(i)
            if self.root[pres]:
                for checks in self.root[pres]:
                    if prefix==checks[:alen]:return True
        return False
            


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
```
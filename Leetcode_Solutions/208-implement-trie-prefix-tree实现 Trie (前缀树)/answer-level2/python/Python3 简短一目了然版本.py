### 解题思路
Python3 简洁，并且合乎Trie定义上形式的版本。
很好理解啦！

### 代码

```python3
class TrieNode(dict):
    def __init__(self):
        self.end = False
        
class Trie:

    def __init__(self):
        self.root=TrieNode()


    def insert(self, word: str) -> None:
        curr=self.root
        for char in word:
            node=curr.get(char)
            if node is None:
                node=TrieNode()
                curr[char]=node
            curr=node
        curr.end=True


    def search(self, word: str) -> bool:
        curr=self.root
        for char in word:
            curr=curr.get(char)
            if curr is None:
                return False
        return curr.end


    def startsWith(self, prefix: str) -> bool:
        curr=self.root
        for char in prefix:
            curr=curr.get(char)
            if curr is None:
                return False
        return True

```
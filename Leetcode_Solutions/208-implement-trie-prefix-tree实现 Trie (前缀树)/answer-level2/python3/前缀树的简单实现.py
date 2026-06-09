### 解题思路
前缀树在算法题中，会经常用到，但是一般没有一个这样的数据结构，通常需要自己去实现。
其实比较简单，就是用一个嵌套的字典，当遇到结束符时，增加“#”即可。

### 代码

```python3
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.tree = {}
    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        temp_tree = self.tree
        for sym in word:
            if sym not in temp_tree:
                temp_tree[sym] ={}
            temp_tree =temp_tree[sym]
        temp_tree["#"] = "#"
    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        temp_tree = self.tree
        for sym in word:
            if sym not in temp_tree:
                return False
            else:
                temp_tree = temp_tree[sym]
        if "#" in temp_tree:
            return  True
        else:
            return False
    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        temp_tree = self.tree
        for sym in prefix:
            if sym not in temp_tree:
                return False
            else:
                temp_tree = temp_tree[sym]
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
```
### 解题思路
本题的关键是如何构造一个前缀树的表示方法；

前缀树的表示方法：其中`trie[i]`为一个字典结构，表示第i个节点的边的情况，若`trie[1]['b']=5`，其意思为第2个节点存在一个表示字符`b`的边，并且该边指向第5个节点；同时再用列表`color[i]=1`表示节点i为单词的尾节点，否则不是；

本题中用一个辅助变量`self.k`来表示下一个节点的编号；每次增加一个节点，`self.k+=1`，并且更新`trie, color`的大小；
### 代码

```python3
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.k = 1
        self.charset = 26
        self.trie = [{}]
        self.color = [0]

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        p = 0
        for i in range(len(word)):
            if word[i] not in self.trie[p]:
                self.trie[p][word[i]] = self.k
                self.trie.append({})
                self.color.append(0)
                self.k += 1
            p = self.trie[p][word[i]]
        self.color[p] = 1

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        p = 0
        for i in range(len(word)):
            if word[i] not in self.trie[p]:
                return False
            p = self.trie[p][word[i]]
        
        if self.color[p]:
            return True
        else:
            return False

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        p = 0
        for i in range(len(prefix)):
            if prefix[i] not in self.trie[p]:
                return False
            p = self.trie[p][prefix[i]]
        
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
```
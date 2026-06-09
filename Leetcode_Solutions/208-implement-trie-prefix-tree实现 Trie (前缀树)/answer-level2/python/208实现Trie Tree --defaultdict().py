### 解题思路
#### 设置TrieNode类
节点包含2属性：children：孩子节点和is_word:是否单词的判断
children:使用默认词典，默认值为一个TrieNode类
is_word:初始为False
#### 类Trie的实现
##### 1.insert
从根节点开始，一条线路表示为一个单词（每个节点表示一个字母）,最后一个节点记录这是一个单词（is_word->True）
##### 2.search
从根节点开始，查询单词,若这条线路顺序查找不到要查找的字母，则返回false，否则返回节点的is_word属性
##### 3.startsWith
从根节点开始，查询单词,若这条线路顺序查找不到要查找的字母，则返回false，否则返回True

### 代码

```python3
from collections import defaultdict
#前缀树的节点包含2属性：children：孩子节点和is_word:是否单词的判断
class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.is_word = False
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()#根节点

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        current = self.root#从根节点开始，一条线路表示为一个单词（每个节点表示一个字母）,最后一个节点记录这是一个单词
        for letter in word:
            current = current.children[letter]
        current.is_word = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        current = self.root#从根节点开始，查询单词
        for letter in word:
            current = current.children.get(letter)
            if current is None:
                return False
        return current.is_word


    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        current = self.root#和search类似，只有返回输入和返回不同
        for letter in prefix:
            current = current.children.get(letter)
            if current is None:
                return False
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
```
### 解题思路
一、建议首先看leetcode 208题：实现Trie（前缀树）。
二、首先建立TrieNode类，它是前缀树的节点，有两个属性：end为True时表示以该节点为结尾的单词存在；children表示该节点的子节点。
三、在二的基础上建立Trie类，里面定义两个方法。其中insert()用于向树中添加单词；search()用于检索该单词的前n项子字符串是否都在树中，举个例子就是：当'moffy'中的'm'、'mo'、'mof'、'moff'、'moffy'都在树中时，则返回True。
四、所有类建好后，遍历两次words。第一次遍历向树中添加所有单词，构造好前缀树；第二次遍历，在构造好的前缀树中找到满足条件的单词，注意最后结果是：保证单词长度最长；当单词长度一样时，选择字典序靠前的单词。

### 代码

```python3
class Solution:
    def longestWord(self, words: List[str]) -> str:
        res=''
        trie=Trie()
        for word in words:
            trie.insert(word)
        for word in words:
            if trie.search(word):
                if len(word) > len(res):
                    res=word
                elif len(word)==len(res) and word < res:
                    res=word
        return res

class TrieNode:
    def __init__(self):
        self.end=False
        self.children=collections.defaultdict(TrieNode)

class Trie:
    def __init__(self):
        self.root=TrieNode()

    def insert(self, word: str) -> None:
        node=self.root
        for s in word:
            node=node.children[s]
        node.end=True

    def search(self, word: str) -> bool:
        node=self.root
        for s in word:
            node=node.children.get(s)
            if node is None or not node.end:
                return False
        return True
```
这是从探索卡片得来的方法。理论介绍请看[相应卡片](https://leetcode-cn.com/explore/learn/card/trie/165/introduction-to-trie/642/)，下面是实现代码。
### 方法一：哈希字典表示子树
前缀树根节点是空字符串，子节点是N叉树的子节点。子节点们可以用哈希字典表示，key是字符，value是该字符对应的子树。
注意当插入结束时将`isword`属性设为`True`。
```python
class Trie:

    def __init__(self,val='',isword=False):
        self.val = val
        self.isword = isword
        self.children = {}

    def insert(self, word: str) -> None:
        cur = self
        for v in word:
            if v not in cur.children:
                cur.children[v] = Trie(v)
            cur = cur.children[v]
        cur.isword=True

    def search(self, word: str) -> bool:
        cur = self
        for v in word:
            cur = cur.children.get(v)
            if cur==None:return False            
        return cur.isword

    def startsWith(self, prefix: str) -> bool:
        cur = self
        for v in prefix:
            cur = cur.children.get(v)
            if cur==None:return False
        return True
```

### 方法二：数组表示子树
前缀树根节点是空字符串，子节点是N叉树的子节点。由于字母只有26个，所以子节点们可以用长度26,各元素为`None`的数组表示，比如前缀有`'b'`,就将数组第二位设为Trie(b)。
```python
class Trie:

    def __init__(self,val='',isword=False):
        self.val = val
        self.isword = isword
        self.children = [None]*26

    def insert(self, word: str) -> None:
        cur = self.children
        for i,v in enumerate(word):
            ii = ord(v)-ord('a')
            if cur[ii]==None:
                cur[ii] = Trie(v,i==len(word)-1)
            else:
                cur[ii].isword |= i==len(word)-1
            cur = cur[ii].children

    def search(self, word: str) -> bool:
        cur = self.children
        for i,v in enumerate(word):
            ii = ord(v)-ord('a')
            if cur[ii]==None:return False
            if i==len(word)-1: return cur[ii].isword
            cur = cur[ii].children            
        return False

    def startsWith(self, prefix: str) -> bool:
        cur = self.children
        for v in prefix:
            ii = ord(v)-ord('a')
            if cur[ii]==None:return False
            cur = cur[ii].children
        return True
```
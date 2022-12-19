### 解题思路
要自定义个TireNode类, 用defaultdict实现, 而不用一个长度26的数组实现, 这样节省了空间
# dict的value是TireNode对象而不是字符 是关键!

### 代码

```python3
from collections import defaultdict
class TireNode:
    def __init__(self):
        self.node = defaultdict(TireNode) # dict的value是TireNode对象而不是字符
        self.isEnd = False

class Trie:
    def __init__(self):
        self.root = TireNode()

    def insert(self, word: str) -> None:
        cur = self.root        
        for w in word:
            cur = cur.node[w]
        cur.isEnd = True

    def search(self, word: str) -> bool:
        cur = self.root
        for w in word:
            if w in cur.node:
                cur = cur.node[w]
            else: return False
        return cur.isEnd

    def startsWith(self, prefix: str) -> bool:
        cur = self.root
        for p in prefix:
            if p in cur.node: cur = cur.node[p]
            else: return False
        return True
```

但是发现直接用d={}字典更快些
```
class Trie(object):
	def __init__(self):
		self.trie = {}

	def insert(self, word):
		t = self.trie
		for c in word:
			if c not in t: t[c] = {}
			t = t[c]
		t["-"] = True # 这里的'-'就相当于前面声明的isEnd, 用来标记是不是结束了, 因为是用字典实现的所以可以随便声明key去标记

	def search(self, word):
		t = self.trie
		for c in word:
			if c not in t: return False
			t = t[c]
		return "-" in t

	def startsWith(self, prefix):
		t = self.trie
		for c in prefix:
			if c not in t: return False
			t = t[c]
		return True
```
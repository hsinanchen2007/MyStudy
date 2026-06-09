### 解题思路
此处撰写解题思路

### 代码

```python3
#tireNode = collections.namedtuple('tireNode', 'children')
class tireNode:
    def __init__(self):
        self.children = [None] * 26

class tireTree:
    def __init__(self):
        self.root = tireNode()
    def insert(self, word):
        def insert(node, word, i, new=False):
            if i < 0: return new
            char = word[i]
            index = ord(char) - ord('a')
            if node.children[index] is None:
                new = True
                node.children[index] = tireNode()
            new = insert(node.children[index], word, i-1, new)
            return new
        lenth = len(word)
        new = insert(self.root, word, lenth-1)
        return lenth+1 if new else 0

class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        tire = tireTree()
        lenth = 0
        words.sort(reverse=True, key = len)
        for word in words:
            lenth += tire.insert(word)
        return lenth

```
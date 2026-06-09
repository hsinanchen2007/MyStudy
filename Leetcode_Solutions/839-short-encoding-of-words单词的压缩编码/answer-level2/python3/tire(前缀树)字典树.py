### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        class Node():
            def __init__(self,l):
                self.l=l 
                self.children={}
        root=Node(0)
        def build(x,w):
            if not w:return 
            if w[-1] not in x.children:
                x.children[w[-1]]=Node(x.l+1)
            build(x.children[w[-1]],w[:-1])
        for w in words:
            build(root,w)
        ans=[0]
        def vis(x):
            if len(x.children)==0:
                if x.l>0:
                    ans[0]+=x.l+1
            for c in x.children.values():
                vis(c)
        vis(root)
        return ans[0]
```
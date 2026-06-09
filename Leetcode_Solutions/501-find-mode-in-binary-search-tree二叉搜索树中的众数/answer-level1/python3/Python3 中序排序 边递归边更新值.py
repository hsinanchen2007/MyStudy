中序遍历， 遇到次数大的就更新列表，相等就加入列表。
```python3 []
class Solution:
    def __init__(self):
        self.cnt = 0
        self.qian = None
        self.n = 0
        
    def findMode(self, root: TreeNode) -> List[int]:
        r = []
    
        def zhong(p):
            if not p:
                return
            else:
                zhong(p.left)
                if not r:
                    r.append(p.val)
                    self.n += 1
                    self.cnt += 1
                    self.qian = p.val
                else:
                    if p.val != self.qian:
                        self.cnt = 1
                        self.qian = p.val
                    else:
                        self.cnt += 1
                    if self.cnt == self.n:
                        r.append(p.val)
                    elif self.cnt>self.n:
                        r.clear()
                        r.append(p.val)
                        self.n = self.cnt
                zhong(p.right)
                return
        
        zhong(root)
        return r
```

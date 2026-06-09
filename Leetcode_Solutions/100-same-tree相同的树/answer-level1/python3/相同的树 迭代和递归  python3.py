### 解题思路
迭代使用列表的pop的函数两两进行比较
递归比较简单
### 代码
#迭代
```python3
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if not p and not q:
            return True
        if not p or not q:
            return False
        if p.val != q.val:
            return False
        queue = [p, q]
        while queue:
            qTmp = queue.pop()
            pTmp = queue.pop()
            if not pTmp and not qTmp:
                continue
            if not pTmp or not qTmp:
                return False
            if pTmp.val != qTmp.val:
                return False
            queue.append(pTmp.left)
            queue.append(qTmp.left)
            
            queue.append(pTmp.right)
            queue.append(qTmp.right)
            
        return True
递归

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if not p and not q:
            return True
        if not p or not q:
            return False
        if p.val != q.val:
            return False
        else:
            l = self.isSameTree(p.left, q.left)
            r = self.isSameTree(p.right, q.right)
            return l and r```

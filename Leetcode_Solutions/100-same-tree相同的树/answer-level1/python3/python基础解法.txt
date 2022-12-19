### 解题思路
1. 递归，第一想法这个递归可以解决，去判断每个节点是否相等，出口就是当都不存在，只有一个不存在，两个值不等
2. 利用迭代也能解决，写一个check函数判断是否有结果，利用list存储，同时利用pop(0)模仿队列效果，也可以用collections里面的deque队列

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        # if not p and not q:
        #     return True
        # if not q or not p:
        #     return False
        # if p.val != q.val:
        #     return False
        # return self.isSameTree(p.right, q.right) and self.isSameTree(p.left, q.left)
        def check(p, q):
            if not p and not q:
                return True
            if not q or not p:
                return False
            if p.val != q.val:
                return False
            return True
        
        queue = [(p, q)]
        while len(queue):
            p, q = queue.pop(0)
            if not check(p, q):
                return False
            if p:
                queue.append((p.left, q.left))
                queue.append((p.right,q.right))
        return True
```
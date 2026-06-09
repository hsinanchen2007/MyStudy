### 解题思路
用循环控制层，用栈控制方向，用Falg控制左右子树的访问顺序
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        queue=collections.deque()
        queue.append(root)
        res=[]
        Falg=False
        while queue:
            s=[]
            stack=[]
            for _ in range(len(queue)):
                p=queue.popleft()
                s.append(p.val)
                stack.append(p)
            while stack:
                p=stack.pop()
                if not Falg:
                    if p.right:
                        queue.append(p.right)
                    if p.left:
                        queue.append(p.left)
                else:
                    if p.left:
                        queue.append(p.left)
                    if p.right:
                        queue.append(p.right)
            Falg=not Falg
            res.append(s)
        return res
```
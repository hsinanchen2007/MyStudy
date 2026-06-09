### 解题思路
**1.迭代**
中序遍历 构造新树
### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def increasingBST(self, root):
        if not root:return []
        stack = []
        ans = []
        while stack or root:
            if root:
                stack.append(root)
                root = root.left
            else:
                root = stack.pop()
                ans.append(root.val)
                root = root.right
        #创建一棵新树
        res = cur = TreeNode(None)
        for c in ans:
            cur.right = TreeNode(c)
            cur = cur.right
        return res.right


```
### 解题思路
**2.递归**
```python
class Solution(object):
    def increasingBST(self, root):
        self.stack = []
        self.ans = []
        def inorder(root):
            if root:
                self.stack.append(root)
                root = root.left
                inorder(root)
            else:
                if self.stack:
                    root = self.stack.pop()
                    self.ans += [root.val]
                    root = root.right
                    inorder(root)
        inorder(root)
        #创建一棵新树
        res = cur = TreeNode(None)
        for c in self.ans:
            cur.right = TreeNode(c)
            cur = cur.right
        return res.right
```

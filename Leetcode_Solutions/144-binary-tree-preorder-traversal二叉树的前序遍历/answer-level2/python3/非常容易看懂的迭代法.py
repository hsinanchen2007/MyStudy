#### 照着Python速度第一大佬的代码自己写了一下，非常简结，比自己写的要好，而且速度还快

```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def preorderTraversal(self, root):
        if root is None:
            return []
        stack = [root]
        ans = []
        while stack:
            tail = stack.pop()
            ans.append(tail.val)
            if tail.right:  # 先检查右子节点
                stack.append(tail.right)
            if tail.left:  # 再检查左子节点， 这样出栈时就是先左后右的顺序
                stack.append(tail.left)
        return ans
```
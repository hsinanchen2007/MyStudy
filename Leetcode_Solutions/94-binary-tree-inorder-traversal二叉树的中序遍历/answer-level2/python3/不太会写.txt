### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        stack1 = [root]
        stack2 = [] # 用作标记
        lst = []
        while stack1:
            node = stack1.pop()
            if node not in stack2:
                if node.right:
                    stack1.append(node.right)
                stack1.append(node)
                stack2.append(node)
                if node.left:
                    stack1.append(node.left)
            else:
                lst.append(node.val)
        return lst
```
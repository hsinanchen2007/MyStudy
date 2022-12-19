### 解题思路
双99
优化版本

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        # 非递归
        stack = []
        # 这里使用一个双端队列，直接在首部O(1)的插入元素，避免逆序整个栈
        res = deque()
        if root is None:
            return None
        # 后序为左右中，前序为中左右，中序为前中右====>后序(左右中)=伪前序入栈(中右左)+出栈(左右中)
        stack.append(root)
        while stack:
            node = stack.pop()
            res.appendleft(node.val)
            # 先压左 在压右
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        return res
```
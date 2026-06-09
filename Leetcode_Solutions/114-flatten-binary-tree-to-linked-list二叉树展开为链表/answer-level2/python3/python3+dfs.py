### 解题思路
dfs+栈
![UC截图20200101151643.png](https://pic.leetcode-cn.com/83ddd78b8d1812a3e77219171f8c20ac628f21201d191a1e900deb930eca967e-UC%E6%88%AA%E5%9B%BE20200101151643.png)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root:
            return root
        head = root
        stack = [root]
        while stack:
            if root.right:
                stack.append(root.right)
            if root.left:
                root.right = root.left
                root.left = None
                root = root.right
            else:
                cur = stack.pop()
                if cur == head:
                    continue
                root.right = cur
                root.left = None
                root = cur
            
        return head

```
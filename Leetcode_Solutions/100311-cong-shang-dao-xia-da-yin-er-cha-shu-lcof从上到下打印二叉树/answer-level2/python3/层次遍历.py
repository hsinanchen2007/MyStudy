### 解题思路
使用队列进行层次遍历

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        if root == None:
            return []

        nums = []
        queue = [root]
        while queue:
            node = queue.pop(0)
            nums.append(node.val)

            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        return nums
```
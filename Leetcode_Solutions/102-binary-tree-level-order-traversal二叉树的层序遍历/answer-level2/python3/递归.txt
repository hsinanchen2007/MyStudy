### 解题思路
用try来判断这一层是否在res里面，不在就添加

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode):
        # 这个就前序遍历呗
        if root is None:
            return []
        res = []
        def helper(root,depth):
            if root:
                try:
                    res[depth].append(root.val)
                except:
                    res.append([root.val])
                depth += 1
                helper(root.left, depth)
                helper(root.right, depth)
        helper(root, 0)
        return res
```
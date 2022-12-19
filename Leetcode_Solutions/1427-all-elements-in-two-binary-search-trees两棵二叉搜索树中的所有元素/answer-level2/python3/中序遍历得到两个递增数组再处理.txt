### 解题思路
中序遍历得到两个递增数组再处理

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        res1 = self.helper(root1)
        res2 = self.helper(root2)
        res = res1 + res2
        res.sort()
        return res
    

    def helper(self,root):
        if not root:
            return []
        else:
            return self.helper(root.left) + [root.val] + self.helper(root.right)
```
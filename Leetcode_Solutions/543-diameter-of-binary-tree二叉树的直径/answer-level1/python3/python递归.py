### 解题思路
如果叶节点为空，返回0，不为空，返回左右子数最大加1

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.res=0
        def findPath(root):
            if not root:
                return 0
            left=findPath(root.left)
            right=findPath(root.right)
            self.res=max(self.res,left+right)
            return max(left,right)+1
        findPath(root)
        return self.res


        
```
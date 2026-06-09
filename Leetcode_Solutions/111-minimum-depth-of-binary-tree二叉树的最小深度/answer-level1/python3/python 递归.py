### 解题思路
递归左右子树，返回深度+1，一定是根节点到叶节点的距离 例如1，2 这种树，返回是2不是1，因为根节点到叶节点只有一种路径
1->2

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        def depth(root):
            if not root:
                return 0
            if not root.left and not root.right:
                return 1
            left,right=float("inf"),float("inf")
            if root.left:
                left=depth(root.left)
            if root.right:
                right=depth(root.right)
            return min(left,right)+1

        return depth(root)

      
```
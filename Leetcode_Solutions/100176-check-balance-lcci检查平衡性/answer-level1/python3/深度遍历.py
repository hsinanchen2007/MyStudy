（1） 因为要检查所有节点是否都平衡，因此我们需要遍历所有节点，看是否都满足条件，如果不满足条件则返回False
（2） depthBinary()的作用是返回当前节点的最大深度
（3） 首先检查根节点，看根节点的左右子树的长度相差是否在1以内，如果在1之外，则返回False
（4） 当根节点符合要求，则检查其左节点和右子节点是否符合要求
（5） 如果都符合则返回True

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if not root:
            return True
        
        def depthBinary(root):   # 用于查询当前节点的深度
            if not root:
                return 0
            return max(depthBinary(root.left),depthBinary(root.right)) + 1  # 获得其左子树和右子树的最大深度，+1就得到了根节点的最大深度
        
        if abs(depthBinary(root.left)-depthBinary(root.right))>1:  # 如果当前节点是不平衡的，返回False
            return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)  # 比较其做子节点和右子节点
```

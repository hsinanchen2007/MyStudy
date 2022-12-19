
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        # 用两个递归，一个为通过root的数目f1(root,sum)，一个为不通过root的数目f2(root,sum)，结果是f1(root,sum)+f2(root,sum)
        def f1(root,sum):
            # 路径必须通过root的数量
            if root==None:return 0 
            return f1(root.left,sum-root.val)+f1(root.right,sum-root.val)+int(root.val==sum)
            # 这里需要注意不要漏掉int(root.val==sum)，这是因为如果root.val==sum，只有root的路径也是一种满足条件的情况，需要加上
        def f2(root,sum):
            # 路径必须不通过root的数量
            if root==None:return 0
            return f1(root.left,sum)+f2(root.left,sum)+f1(root.right,sum)+f2(root.right,sum)
        return f1(root,sum)+f2(root,sum)
```


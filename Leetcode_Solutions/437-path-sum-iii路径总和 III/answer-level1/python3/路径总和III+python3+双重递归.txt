### 双重递归
两种情况：
1. 当前节点为满足条件的一部分，因此要保持连续性。这一部分通过函数find实现；
2. 在当前节点的后面部分，有满足要求的情况（舍弃前面），因此对左右子树进行递归；

代码如下：
```
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        def find(root,sum):
            if root and root.val== sum:
                return 1+find(root.left,0)+find(root.right,0)
            if not root:
                return 0
            return find(root.left, sum-root.val)+find(root.right,sum-root.val)        
        if not root:
            return 0
        if root:
            left = self.pathSum(root.left,sum)
            right = self.pathSum(root.right,sum)
            l = find(root.left,sum-root.val)
            r = find(root.right,sum-root.val)
            if sum == root.val:
                return 1+left+right+l+r
            else:
                return left+right+l+r
```

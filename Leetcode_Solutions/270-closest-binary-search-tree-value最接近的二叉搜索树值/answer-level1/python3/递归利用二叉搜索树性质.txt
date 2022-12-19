### 解题思路
如果目标值大于当前节点的值，那么舍掉当前节点的左子树
如果目标节点的值小于当前节点，那么舍掉当前节点的右子树

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def closestValue(self, root: TreeNode, target: float) -> int:
        self.res=float("inf")
        def findclose(root):
            if not root:
                return
            if abs(root.val-target)<abs(target-self.res):
                self.res=root.val
            if target>root.val:
                findclose(root.right)
            else:
                findclose(root.left)
        findclose(root)
        return self.res

       
```
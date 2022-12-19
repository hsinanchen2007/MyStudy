### 解题思路
递归地检测每一个点x，以x为根，判断左右子树是否深度相差不超过1.  
树深度的检测中使用层遍历，每过1层深度加1.

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def treeHight(self, root: TreeNode) -> int:
        h = 0
        if not root:
            return h
        l1 = [root]
        while l1:
            l2 = []
            h = h + 1
            for x in l1:
                if x.left:
                    l2.append(x.left)
                if x.right:
                    l2.append(x.right)
            l1 = l2
        return h
    def isBalanced(self, root: TreeNode) -> bool:
        if not root:
            return True
        h1 = self.treeHight(root.left)
        h2 = self.treeHight(root.right)
        if h1-h2>1 or h1-h2<-1:
            return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)

```
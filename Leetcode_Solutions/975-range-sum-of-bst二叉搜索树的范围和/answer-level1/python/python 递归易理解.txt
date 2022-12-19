### 解题思路
将当前节点的值与边界[L,R]比较，分为3种情况。
L<=val and val<=R
val<L
val>R

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rangeSumBST(self, root, L, R):
        """
        :type root: TreeNode
        :type L: int
        :type R: int
        :rtype: int
        """
        if not root:
            return root
        res=[]
        def Traversal(node,L,R):
            if not node:
                return
            if node.val<L:#当前值小于左边界，递归右子树
                Traversal(node.right,L,R)
            elif node.val>R:#当前值大于右边界，递归左子树
                Traversal(node.left,L,R)
            else:#在边界内，加入数组，然后递归左子树+递归右子树
                res.append(node.val)
                Traversal(node.left,L,R)
                Traversal(node.right,L,R)
        Traversal(root,L,R)
        print(res)
        return sum(res)
            
```
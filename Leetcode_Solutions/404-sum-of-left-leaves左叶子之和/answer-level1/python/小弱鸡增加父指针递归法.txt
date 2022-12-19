### 解题思路
同样的采用递归遍历树的方式，只不过这次需要增加一个指向父节点的指针，当为叶节点时，利用父节点进行判断，是否需要加和
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        if root==None:
            return 0
        if root.left==None and root.right==None:
            return 0
        self.res=0
        def helper(father,child):
            if child.left==None and child.right==None and child==father.left:
                self.res+=child.val
            elif child.left==None and child.right==None and child==father.left:
                return
            elif child.left!=None and child.right==None:
                helper(child,child.left)
            elif child.left==None and child.right!=None:
                helper(child,child.right)
            elif child.left!=None and child.right!=None:
                helper(child,child.left)
                helper(child,child.right)
        if root.left==None and root.right!=None:
            helper(root,root.right)
        elif root.left!=None and root.right==None:
            helper(root,root.left)
        elif root.left!=None and root.right!=None:
            helper(root,root.left)
            helper(root,root.right)
        return self.res
```
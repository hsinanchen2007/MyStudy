![image.png](https://pic.leetcode-cn.com/3125a45640f97585ef651f0618e60f74f2b182c5a4540310a2440f5423fa5602-image.png)


### 代码
```python3
# Definition for a binary tree node.

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.Balanced=True

    def isBalanced(self, root: TreeNode) -> bool:            
        if not root:
            return True
        pdeth=0        
        self.isbalanced(root,pdeth)
        return self.Balanced

    def isbalanced(self,root,pdeth):
        ldeth=0
        if root.left:
            ldeth=self.isbalanced(root.left,pdeth+1)
        rdeth=0
        if root.right:
            rdeth=self.isbalanced(root.right,pdeth+1)
        if abs(ldeth-rdeth)>1:
            self.Balanced=False
        return max(ldeth,rdeth)+1
      


```
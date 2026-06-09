### 递归 
递归思路很清晰，就是判断左右子树是否是平衡二叉树以及当前树是否为平衡二叉树（全都要满足，判断的顺序非常重要！！！这里决定你是不是超时......）
```
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if not root:
            return True
        left = self.isBalanced(root.left)
        right = self.isBalanced(root.right)
        return  left and right and self.help_(root) 
        # 这个顺序非常重要，开始把self.help_(root)放前面，结果超时了，至于为什么...
                 
    def deep(self,root):
        if not root:
            return 0
        return 1+max(self.deep(root.left),self.deep(root.right))
    def help_(self,root):
        if not root:
            return True
        return abs(self.deep(root.left)-self.deep(root.right))<=1 
```
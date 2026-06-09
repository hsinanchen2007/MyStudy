从上到下的代码相对简洁，但是其中叶节点会遍历多次，复杂度为o(n^2)
```
class Solution:
    #计算子树的深度
    def TreeNode(self,root):
        if not root:
            return 0
        return max(self.TreeNode(root.left),self.TreeNode(root.right)) + 1

    def isBalanced(self,root):
        if not root:return True
        left  = self.TreeNode(root.left)
        right = self.TreeNode(root.right)

        if abs(left - right) > 1:
            return False
        
        return self.isBalanced(root.left) and self.isBalanced(root.right)
```


从下到上的代码中，每个节点都只会被遍历一次。首先从底部遍历每个节点是不是平衡的.复杂度为o(n)
```
class Solution:
    def TreeNode(self,root):
        if not root:return 0
        return max(self.TreeNode(root.left),self.TreeNode(root.right)) + 1
    
    def isBalanced(self, root: TreeNode) -> bool:
        if not root: return True

        if self.isBalanced(root.left) and self.isBalanced(root.right):
            left  = self.TreeNode(root.left)
            right = self.TreeNode(root.right)

            if abs(left - right) <= 1:
                return True
        
        return False
    
```

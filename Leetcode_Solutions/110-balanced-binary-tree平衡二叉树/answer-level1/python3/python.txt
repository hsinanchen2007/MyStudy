```
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        '''
        #from top to bottom
        if not root: return True
        return abs(self.isBalanced(root.left)-self.depth(root.right))<=1 and self.isBalanced(root.left) and self.isBalanced(root.right)
    
    def depth(self,root):
        if not root: return 0
        return max(self.depth(root.left),self.depth(root.right))+1
        '''
        #from bottom to top
        return self.depth(root)!=-1
    def depth(self,root):
        if not root: return 0
        left = self.depth(root.left)
        if left==-1: return -1
        right = self.depth(root.right)
        if right==-1: return -1
        return max(left,right)+1 if abs(left-right)<2 else -1
```

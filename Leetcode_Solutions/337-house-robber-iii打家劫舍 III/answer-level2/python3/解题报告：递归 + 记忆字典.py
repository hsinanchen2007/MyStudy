不用记忆字典，在Python中会超时的，所以我们用self.back去记忆之前处理过的节点
```
class Solution:
    def __init__(self):
        self.back = {}
    def rob(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        if root.left in self.back:
            leftPrice = self.back[root.left]
        else:
            leftPrice = self.rob(root.left)
            self.back[root.left] = leftPrice
        if root.right in self.back:
            rightPrice = self.back[root.right]
        else:
            rightPrice = self.rob(root.right)
            self.back[root.right] = rightPrice
        
        leftchildLeftPrice = leftchildRightPrice = 0
        if root.left:
            if root.left.left in self.back:
                leftchildLeftPrice = self.back[root.left.left]
            else:
                leftchildLeftPrice = self.rob(root.left.left)
                self.back[root.left.left] = leftchildLeftPrice
            if root.left.right in self.back:
                leftchildRightPrice = self.back[root.left.right]
            else:
                leftchildRightPrice = self.rob(root.left.right)
                self.back[root.left.right] = leftchildRightPrice
        leftchildPrice = leftchildLeftPrice + leftchildRightPrice
        
        rightchildLeftPrice = rightchildRightPrice = 0
        if root.right:
            rightchildLeftPrice = self.rob(root.right.left)
            rightchildRightPrice = self.rob(root.right.right)
        rightchildPrice = rightchildLeftPrice + rightchildRightPrice
        
        return max(leftPrice + rightPrice, root.val + leftchildPrice + rightchildPrice)
        
        
                
        
                
                
                
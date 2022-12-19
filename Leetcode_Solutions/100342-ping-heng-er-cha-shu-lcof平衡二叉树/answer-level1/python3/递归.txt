```
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        self.ans = True
        def judge(root):
            if not self.ans: return -1
            if root == None: return 0 
            left = judge(root.left)
            right = judge(root.right)
            if left == -1 or right == -1: return -1
            if abs(left - right) >1: 
                self.ans = False
                return -1
            return 1 + max(left, right)
        judge(root)
        return self.ans
```

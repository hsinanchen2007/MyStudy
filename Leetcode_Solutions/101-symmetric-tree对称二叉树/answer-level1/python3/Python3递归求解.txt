使用python3，基本思想就是如果一个树是对称的，那么必然左子树和右子树是对称的，而要想判断左右子树是否对称，就递归到了原先的问题。
```
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def check(rleft: TreeNode, rright: TreeNode):
            if rleft == None and rright == None:
                return True
            elif (rleft == None and rright != None) or (rleft != None and rright == None):
                return False
            else:
                if rleft.val != rright.val:
                    return False
                else:
                    return check(rleft.left, rright.right) and check(rleft.right, rright.left)
        
        if root == None:
            return True
        
        return check(root.left, root.right)
```

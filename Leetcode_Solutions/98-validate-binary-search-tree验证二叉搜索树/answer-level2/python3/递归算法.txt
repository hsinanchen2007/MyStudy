更改中序遍历的算法，如果每个当前访问的值都比前一个访问的值大，则是二叉搜索树
需要一个pre记录上一个访问的值
```
class Solution:
    def __init__(self):
        self.pre = None
    def isValidBST(self, root: TreeNode) -> bool:
        if not root:
            return True
        def bianli(root):
            if not root:
                return True
            if root:
                left = bianli(root.left)
                if self.pre==None:
                    self.pre =root.val
                elif self.pre<root.val:
                    self.pre =root.val
                else:
                    return False
                right = bianli(root.right)
                return True if left and right else False
        return bianli(root)
```
第一次写题解，还请大家多多包涵。（我是个菜鸡）

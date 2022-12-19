python 中序遍历
```
class Solution:
    def findTarget(self, root: TreeNode, target: int) -> bool:
        # write your code here
        if root == None:
            return False
        def getNextLeft(root):
            stack = []
            while root or stack:
                while root:
                    stack.append(root)
                    root = root.left
                root = stack.pop()
                yield root
                root = root.right
        def getNextRight(root):
            stack = []
            while root or stack:
                while root:
                    stack.append(root)
                    root = root.right
                root = stack.pop()
                yield root
                root = root.left
        lg = getNextLeft(root)
        rg = getNextRight(root)
        left = lg.__next__()
        right = rg.__next__()
        while left.val < right.val:
            tmp = left.val + right.val
            if tmp < target:
                left = lg.__next__()
            elif tmp > target:
                right = rg.__next__()
            else:
                return True
        return False
```

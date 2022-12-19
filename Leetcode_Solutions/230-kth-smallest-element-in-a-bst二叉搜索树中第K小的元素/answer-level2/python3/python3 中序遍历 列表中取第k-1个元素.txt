class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        a = []
        def func(root):
            if not root:
                return 
            func(root.left)
            a.append(root.val)
            func(root.right)
        func(root)
        a = set(a)
        a = list(a)
        return a[k-1]   
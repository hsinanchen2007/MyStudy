class Solution:
    def isBalanced(self, root: TreeNode) -> bool:

        def height(root):           
            if root is None:
                return (0,True)
            
            l = height(root.left)
            r = height(root.right)

            if abs(l[0]-r[0]) > 1:
                return max(l[0],r[0]) + 1,  False
            return max(l[0],r[0]) + 1,  l[1] and r[1]

        h = height(root)
        return h[1]
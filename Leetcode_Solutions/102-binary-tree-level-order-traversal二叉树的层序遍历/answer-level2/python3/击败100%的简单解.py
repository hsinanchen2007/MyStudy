class Solution(object):
    def levelOrder(sel''' '''  ''' '''f, root):
        res = []
        roots = [root] if root else []
        while roots:
            temp = []
            nextLayer = []
            for root in roots:
                temp.append(root.val)
                if root.left:
                    nextLayer.append(root.left)
                if root.right:
                    nextLayer.append(root.right)
            res.append(temp)
            roots = nextLayer
        return res
        
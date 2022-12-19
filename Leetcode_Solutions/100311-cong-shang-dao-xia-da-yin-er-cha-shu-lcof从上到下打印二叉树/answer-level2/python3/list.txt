class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        res = []
        if root == None:
            return res 
        nodes = [root]
        while nodes:
            tmp = []
            for item in nodes:
                res.append(item.val)
                if item.left: tmp.append(item.left)
                if item.right: tmp.append(item.right)
            nodes = tmp
        return res
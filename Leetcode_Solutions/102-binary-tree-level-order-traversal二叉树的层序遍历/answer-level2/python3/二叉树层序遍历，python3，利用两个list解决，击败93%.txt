class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        res = [[root.val]]
        q = [root]
        while q:
            q_tmp = []
            while q:
                tmp = q.pop(0)
                if tmp.left:
                    q_tmp.append(tmp.left)
                if tmp.right:
                    q_tmp.append(tmp.right)
            if q_tmp:
                res.append([item.val for item in q_tmp])
            q = q_tmp
        return res
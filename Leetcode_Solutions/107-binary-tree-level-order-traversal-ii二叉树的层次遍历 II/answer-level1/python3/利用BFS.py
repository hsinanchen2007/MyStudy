class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        queue = [root]
        res = []
        while queue:
            cur_level_nums = len(queue)
            cur_level_nodes = []
            for i in range(cur_level_nums):
                node = queue.pop(0)
                cur_level_nodes.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            res.insert(0,cur_level_nodes)
            
            
        return res


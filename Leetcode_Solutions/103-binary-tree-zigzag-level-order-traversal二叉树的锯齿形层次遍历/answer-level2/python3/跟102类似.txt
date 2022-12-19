跟102解法差不多，只是在插数的时候，会判断一下是插入到最后面还是最前面

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        # BFS
        res = []

        def helper(node, depth, flag):
            if not node:
                return []

            if len(res) == depth:
                res.append([])

            if flag:
                res[depth].append(node.val)
            else:
                res[depth].insert(0, node.val)
            if node.right:
                helper(node.right, depth + 1, not flag)
            if node.left:
                helper(node.left, depth + 1, not flag)
        
        helper(root, 0, False)
        return res
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        queue=[]
        if root:
            queue.append((1,root))
        cur_depth=0
        while a:
            cur_depth,root=queue.pop(0)
            if root.left:
                queue.append((cur_depth+1,root.left))
            if root.right:
                queue.append((cur_depth+1,root.right))
        depth=cur_depth
        return depth
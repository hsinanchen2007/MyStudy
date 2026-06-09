```
class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        # bfs with recursion, add level flag then merge 2dim list
        if not root:
            return []
        res = [[root.val]]
        def bfs_recursive(root, level):
            if not root:
                return
            if root.left:
                if len(res) <= level:
                    res.append([])
                res[level].append(root.left.val)
            if root.right:
                if len(res) <= level:
                    res.append([])
                res[level].append(root.right.val)
            bfs_recursive(root.left, level + 1)            
            bfs_recursive(root.right, level + 1)
        bfs_recursive(root, 1)
        out = []
        for lv in res:
            out += lv
        return out
```

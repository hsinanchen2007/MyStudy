1.层序遍历
2.中序遍历
记录当前结点的深度，并合最大深度比较即可
```
class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        # 1.BFS 层序遍历
        # queue = [root]
        # while queue:
        #     tmp = []
        #     node = queue[-1]
        #     for q in queue:
        #         if q.right: # 因为要返回最底层最左层结点，所以每一层按先右后左的顺序遍历
        #             tmp.append(q.right)
        #         if q.left:
        #             tmp.append(q.left)
        #     queue = tmp
        # return node.val

        # 2.DFS
        self.max_deep = -1
        self.node = None
        def dfs(root, deep):
            if not root.left and not root.right: # 走到了根结点
                if deep > self.max_deep:
                    self.max_deep = deep
                    self.node = root
            if root.left: # 先往左遍历，再往右；可以确保最终的node一定是最底层最左侧的结点
                dfs(root.left, deep + 1)
            if root.right:
                dfs(root.right, deep + 1)
        dfs(root, 0)
        return self.node.val
```

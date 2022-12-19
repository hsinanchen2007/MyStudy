第一次dfs：求得从根到各个叶节点的和，并且返回给父节点，父节点保存所有以它为根的子树的到叶节点和的列表

第二次dfs：若所有当前节点所有到叶节点的和都小于`limit`，其父节点将其剪枝

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def dfs(self, node, cur_sum):
        sums = []
        if node is not None:
            node.sum = cur_sum + node.val
            lss = self.dfs(node.left, node.sum)
            rss = self.dfs(node.right, node.sum)
            if node.left == None and node.right == None:
                sums.append(node.sum)
            sums.extend(lss)
            sums.extend(rss)
            node.sums = sums
        return sums
    
    def _dfs(self, node, limit):
        if node is None:
            return None
        if all([s < limit for s in node.sums]):
            return None
        node.left = self._dfs(node.left, limit)
        node.right = self._dfs(node.right, limit)
        return node

    def sufficientSubset(self, root: TreeNode, limit: int) -> TreeNode:
        self.dfs(root, 0)
        return self._dfs(root, limit)
```
解题思路，采用递归的方式：
1.如果当前节点是空的，就返回0
2.如果不为空就返回两个子节点中的最大深度加1

```
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        return 0 if not root else max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1

```

-   一遍深度优先搜索

-   由于是路径上面的和值，需要同时向下传递当前路径的值才能判断子路径是否需要删除



```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sufficientSubset(self, root: TreeNode, limit: int) -> TreeNode:
        head = TreeNode(0)
        head.left = root

        def dfs(node: TreeNode, father_sums):
            if not node:
                return 0

            left = dfs(node.left, father_sums + node.val)
            right = dfs(node.right, father_sums + node.val)

            sub_sum = 0
            if node.left and node.right:
                sub_sum = max(left, right)
            elif node.left:
                sub_sum = left
            elif node.right:
                sub_sum = right

            if father_sums + node.val + left < limit:
                node.left = None
            if father_sums + node.val + right < limit:
                node.right = None

            return node.val + sub_sum

        dfs(head, 0)

        return head.left
```



- DFS
- 判断断开的节点：
  - 如果左节点为待删除节点，断开左节点连接
  - 如果右节点为待删除节点，断开右节点连接
- 判断需要添加的节点：
  - 如果当前节点为待删除节点
    - 如果如果左节点不删除，添加左节点
    - 如果如果右节点不删除，添加右节点

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        if not root:
            return []
        res = []
        delete_set = set(to_delete)

        if root.val not in delete_set:
            res.append(root)

        def dfs(node):
            if not node:
                return

            left, right = node.left, node.right

            if node.val in delete_set:
                if left and left.val not in delete_set:
                    res.append(left)
                if right and right.val not in delete_set:
                    res.append(right)
            if left and left.val in delete_set:
                node.left = None

            if right and right.val in delete_set:
                node.right = None

            dfs(left)
            dfs(right)

        dfs(root)
        return res
```



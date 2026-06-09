先来一个深度优先，访问所有的节点，记录每个节点的row和col以及val
具体是：
- 从头节点开始，row = 0, col = 0
- 向左，dfs(root.left, row+1, col-1)
- 向右, dfs(root.right, row+1, col+1)
最后就能得到每个节点的row和col以及val值，
然后根据先col，在row的顺序排序，最后在把排序后的数组根据col值拆成多个数组就成。

```python3
class Solution:
    def verticalOrder(self, root: TreeNode) -> List[List[int]]:
        nodes = []
        def dfs(node, row, col):
            if not node:
                return
            nodes.append((col, row, node.val))
            dfs(node.left, row+1, col-1)
            dfs(node.right, row+1, col+1)
        dfs(root, 0, 0)

        nodes.sort(key=lambda node: (node[0], node[1]))
        result = []
        for i, node in enumerate(nodes):
            if i == 0 or node[0] != nodes[i-1][0]:
                result.append([node[2]])
            else:
                result[-1].append(node[2])
        return result
```
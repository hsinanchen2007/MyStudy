对树进行深度优先搜索，在搜索的时候，记录节点和其对应的`宽度`。例如，根节点的`宽度`是 0，然后对其左节点，入队列，并将其`宽度`置为 -1，右节点也入队列，`宽度`置为 +1。同理遍历整个树即可。

```python3
class Solution:
    def verticalOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        from collections import deque, defaultdict

        res_dict = defaultdict(list)

        queue = deque([(root, 0)])

        while queue:
            node, vert = queue.popleft()

            res_dict[vert].append(node.val)

            # if node is not None:
            if node.left is not None:
                queue.append([node.left, vert-1])
            if node.right is not None:
                queue.append([node.right, vert+1])


        return [res_dict[i] for i in sorted(res_dict.keys())] 

```
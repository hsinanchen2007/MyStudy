```
class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        if not root:
            return 1
        queue = []
        storey = {}

        queue.append(root)
        storey_num = 1
        while queue:
            node_num = len(queue)
            storey_sum = 0
            while node_num:
                node = queue.pop(0)
                storey_sum += node.val
                if node.left is not None:
                    queue.append(node.left)
                if node.right is not None:
                    queue.append(node.right)
                node_num -= 1

            storey[storey_num] = storey_sum
            storey_num += 1
        return sorted(storey.items(), key=lambda x: x[1], reverse=True)[0][0]
```
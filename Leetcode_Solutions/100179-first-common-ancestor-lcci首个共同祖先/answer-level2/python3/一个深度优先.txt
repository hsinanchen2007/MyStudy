定义一个深度优先函数dfs, 返回值是一个元祖（node_count, ancestor)，包括子节点包含的目标节点数量
如果左右两个子节点中，有一个包括了两个目标节点，返回node_count的值就是2，可以直接返回它对应的ancestor
否则检查左右包含的节点相加，以及当前节点是否是目标节点之一，然后返回对应的节点统计。

```python
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def dfs(node):
            if not node:
                return 0, None
            left_count, left_acc = dfs(node.left)
            right_count, right_acc = dfs(node.right)
            if left_count == 2 or right_count == 2:
                return 2, left_acc or right_acc
            
            cur_count = left_count + right_count
            if node.val == p.val or node.val == q.val:
                cur_count += 1
            if cur_count == 2:
                return 2, node
            return cur_count, None
        return dfs(root)[1]
```
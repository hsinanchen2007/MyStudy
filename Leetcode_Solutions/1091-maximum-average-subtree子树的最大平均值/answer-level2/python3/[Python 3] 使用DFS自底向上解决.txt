使用DFS自底向上解决，每次计算出以当前节点为根节点的左右子树的平均值，进行比较；

```python3
class Solution:
    def maximumAverageSubtree(self, root: TreeNode) -> float:
        """ DFS算法解决
        """
        def DFS(root: TreeNode) -> (int, int):
            """
            :param root: 子树根节点
            :return: (子树节点总和, 子树节点个数)
            """
            # 递归终止条件: 当前节点是叶子节点, 子树总和就是该节点的值, 个数为1
            if not root:
                return 0, 0
            elif not (root.left or root.right):
                return root.val, 1

            left_sum, left_nodes = DFS(root.left)
            right_sum, right_nodes = DFS(root.right)
            left = (left_sum / left_nodes) if left_nodes else 0
            right = (right_sum / right_nodes) if right_nodes else 0
            cur_sum, cur_nodes = left_sum + right_sum + root.val, left_nodes + right_nodes + 1
            cur = cur_sum / cur_nodes
            self.max = max(self.max, left, right, cur)
            return cur_sum, cur_nodes

        self.max = 0
        DFS(root)
        return self.max
```


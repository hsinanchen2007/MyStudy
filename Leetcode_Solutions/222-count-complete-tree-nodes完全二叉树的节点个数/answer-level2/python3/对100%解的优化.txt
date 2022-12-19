> 【左链长】：结点一直向左到底的路径长度
> 【右链长】：结点一直向右到底的路径长度

- **性质**：若左链长等于右链长，则为满二叉
- **递归函数功能**：返回当前子树的结点数量
- **递归函数终止条件**：根节点为空；当前满二叉。
- **递归函数逻辑**：左子树结点数+右子树节点数+1
- **直接递归存在的问题**：左链长和右链长存在重复计算
- **解决方法**：将下一层将用到的、已经计算的链长传入递归函数

```python
class Solution:
    def countNodes(self, root: TreeNode) -> int:

        def left_length(node):
            count = 0
            while node:
                node = node.left
                count += 1
            return count

        def right_length(node):
            count = 0
            while node:
                node = node.right
                count += 1
            return count

        def count_nodes(node, left_len=None, right_len=None):
            if not node:
                return 0
            left_len = left_len if left_len else left_length(node)
            right_len = right_len if right_len else right_length(node)
            if left_len == right_len:  # 满二叉
                return (1 << left_len) - 1
            return count_nodes(node.left, left_len=left_len-1) + count_nodes(node.right, right_len=right_len-1) + 1
        
        return count_nodes(root)
```
                
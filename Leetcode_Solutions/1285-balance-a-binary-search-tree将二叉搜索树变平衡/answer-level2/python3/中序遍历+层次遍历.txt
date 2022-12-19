中序遍历获取二叉搜索树节点值升序序列，再按层次遍历构建二叉搜索树，即为平衡二叉搜索树

注意：获取的所有节点断掉之前链接——左、右子节点皆指向None

```python3
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        stack = deque()
        cur = root
        nodes = []
        while len(stack) > 0 or cur:
            if cur:
                stack.append(cur)
                cur = cur.left
            else:
                cur = stack.pop()
                nodes.append(cur)
                right = cur.right
                cur.left = None
                cur.right = None
                cur = right
        head = self.struct_bst(nodes, 0, len(nodes) - 1)
        return head

    def struct_bst(self, nodes, left, right):
        if left > right:
            return None
        if left == right:
            return nodes[left]
        mid = (left + right) // 2
        nodes[mid].left = self.struct_bst(nodes, left, mid - 1)
        nodes[mid].right = self.struct_bst(nodes, mid + 1, right)
        return nodes[mid]
```

AVL树旋转类型调整，我没记住.....，现场手写，我估计来不及，所以你懂的......
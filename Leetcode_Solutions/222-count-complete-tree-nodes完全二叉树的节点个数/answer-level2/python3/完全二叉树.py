## 思路:

暴力，每个节点都访问一下，看有多少个

时间复杂度：$O(n)$

```python
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        if not root: return 0
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)
```

这样不是完全二叉树也可以计算，但是没有用到完全二叉树的性质！

我们可以通过运用性质，完全二叉树的节点个数等于 $2^{h} - 1$，

所以有，时间复杂度：$O(log(n)^2)$

```python
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        if not root: return 0
        left_height = 0
        left_node = root
        right_height = 0
        right_node = root
        while left_node:
            left_node = left_node.left
            left_height += 1
        while right_node:
            right_node = right_node.right
            right_height += 1
        if left_height == right_height:
            return pow(2,left_height) - 1
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)
```


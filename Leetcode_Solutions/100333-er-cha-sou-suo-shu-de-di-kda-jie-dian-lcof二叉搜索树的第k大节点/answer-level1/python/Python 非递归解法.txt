遍历方式是 右 根 左, 这样元素从大到小排列好, 当得到第k个节点的时候直接输出即可

```python
class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        if not root:
            return None
        stack = []
        node = root
        while stack or node:
            # 寻找右子树
            while node:
                stack.append(node)
                node = node.right
            # while 结束当前节点没有右子树
            k -= 1
            node = stack.pop()
            if k == 0:
                return node.val
            node = node.left # 把左子树一个节点放入

```
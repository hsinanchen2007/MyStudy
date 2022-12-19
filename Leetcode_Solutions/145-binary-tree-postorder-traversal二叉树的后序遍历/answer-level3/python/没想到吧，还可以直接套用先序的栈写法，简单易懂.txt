```python
class Solution:
    # 直接套用先序遍历的栈写法即可，
    # 因为先序是“根左右”而后序是“左右根”，所以模仿先序生成“根右左”再反转输出就是“左右根了”
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        stack, node, res = [], root, []
        while stack or node:
            while node:
                stack.append(node)
                res.append(node.val)
                node = node.right  # 这里和下面交换了原版先序的顺序
            node = stack.pop()
            node = node.left  # 这里和上面交换了原版先序的顺序
        return reversed(res)
```

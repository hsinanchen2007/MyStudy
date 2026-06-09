依旧是遍历的思想，但不会太暴力，方法就是如果一个节点的值等于根节点的值，那么就不要再入栈了。
```python []
class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        first, second = root.val, -1
        stack = [root]
        while stack:
            t = stack.pop()
            for node in [t.left, t.right]:
                if node:
                    if node.val == first:
                        stack.append(node)
                    elif second == -1 or second > node.val:
                        second = node.val
        return second
```

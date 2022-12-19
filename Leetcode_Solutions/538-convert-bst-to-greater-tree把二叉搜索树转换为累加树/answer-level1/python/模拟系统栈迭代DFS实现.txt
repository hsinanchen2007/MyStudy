一开始最好自己过一遍三层树的例子，然后就会发现规律。

![image.png](https://pic.leetcode-cn.com/7709645428bd2d60722dca0fcce44c4e2d8905b20af8d05b3794499f159632d1-image.png)

是深度优先，右中左不断的叠加。

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        stack = [(root,1)]
        sum = 0
        while stack:
            node, cmd = stack.pop()
            if node is None:
                continue
            if cmd == 0:
                sum += node.val
                node.val = sum
            else:
                stack.append((node.left, 1))
                stack.append((node, 0))
                stack.append((node.right, 1))
        return root
```

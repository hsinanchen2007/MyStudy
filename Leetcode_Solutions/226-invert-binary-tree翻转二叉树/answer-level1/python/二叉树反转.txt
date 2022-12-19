### 解题思路
这里要知道root是一个节点对象（TreeNode），然后就是利用递归解决该问题，还有就是要注意边界的判断，即什么时候结束

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def invertTree(self, root):
        if not root:
            return
        temp_val = root.left
        root.left = root.right
        root.right = temp_val
        if root.left:
            self.invertTree(root.left)
        if root.right:
            self.invertTree(root.right)

        return root


```
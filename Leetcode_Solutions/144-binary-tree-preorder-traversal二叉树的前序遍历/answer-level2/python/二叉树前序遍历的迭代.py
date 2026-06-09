### 解题思路
1、前序遍历，根>左>右
2、栈，后入先出，维护栈，依次压入右节点、左节点
3、依次弹出，循环迭代至栈为空

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return
        stacks = [root]
        res = []
        while len(stacks)>0:
            node = stacks.pop()
            res.append(node.val)
            if node.right:
                stacks.append(node.right)
            if node.left:
                stacks.append(node.left)
        return res
```
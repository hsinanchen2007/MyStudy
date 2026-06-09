> 比较简单的思路：
- 根据树的深度使用‘#’将树补全成满二叉树
- 在重建时需要维护一个待添加左右子节点的树节点的队列
```python
from collections import deque

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        res = []
        stack = deque([root])
        while stack:
            top = stack.popleft()
            if top:
                res.append(str(top.val))
                stack.append(top.left)
                stack.append(top.right)
            else:
                res.append('#')
        print(res)
        return '|'.join(res)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        data = data.split('|')
        if data[0] == '#':
            return None
        root = TreeNode(data[0])
        data = deque(data[1:])
        stack = deque([root])
        while stack:
            cur = stack.popleft()
            left = data.popleft()
            right = data.popleft()
            if left != '#':
                left = TreeNode(left)
                cur.left = left
                stack.append(left)
            if right != '#':
                right = TreeNode(right)
                cur.right = right
                stack.append(right)
        return root

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
```
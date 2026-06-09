```
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
        re = ''
        def helper(root):
            nonlocal re
            if root is None:
                re += 'None,'
                return
            re += str(root.val) + ','
            helper(root.left)
            helper(root.right)
            
        helper(root)
        return re
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        :type data: str
        :rtype: TreeNode
        """
        data = data.split(',')[:-1]
        def helper():
            d = data.pop(0)
            if d == 'None':
                return None
            root = TreeNode(int(d))
            root.left = helper()
            root.right = helper()
            return root

        root = helper()
        return root
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
```

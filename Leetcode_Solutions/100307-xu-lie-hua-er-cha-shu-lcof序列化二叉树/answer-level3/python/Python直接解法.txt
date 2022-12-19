### 解题思路
第一次自己写出hard题纪念。
序列化就是层次遍历。
反序列化建立节点列表，与输入的值列表配合判断。

### 代码

```python3
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
        if root == None:
            return []
        stack = [root]
        res = []
        while stack:
            node = stack.pop(0)
            if node == None:
                res.append('null')
            else:
                res.append(node.val)
                stack.append(node.left)
                stack.append(node.right)
        return res
            

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if data == [] or data[0] == 'null':
            return None
        root = TreeNode(data.pop(0))
        nodes = [root]
        while len(data) >= 2:
            node = nodes.pop(0)
            if node == None:#这个判断需要写在前面，节点为None时，不能从data里pop数值。
                continue
            num = data.pop(0)
            if num == 'null':
                node.left = None
            else:
                node.left = TreeNode(num)
            num = data.pop(0)
            if num == 'null':
                node.right = None
            else:
                node.right = TreeNode(num)
            nodes.append(node.left)
            nodes.append(node.right)
        return root

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
```
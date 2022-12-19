```python
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
        # BFS
        res = []
        queue = [root]
        while queue != []:
            node = queue.pop(0)
            if node == None:
                res.append('null')
            else:
                res.append(str(node.val))
                queue.append(node.left)
                queue.append(node.right)
        while res and res[-1] == 'null': res.pop()
        return '[' +  ','.join(res) + ']'
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if data == '[]': return None
        data = data[1:-1].split(',')
        
        for i in range(len(data)):
            if data[i] == 'null': data[i] = None
        

        cur = dummyHead = TreeNode(data[0])
        queue = [cur]
        index = 1
        while index < len(data):
            node = queue.pop(0)
            if data[index] != None:
                node.left = TreeNode(data[index])
                queue.append(node.left)
            else: node.left = None
            index += 1
            if index == len(data): break
            if data[index] != None:
                node.right = TreeNode(data[index])
                queue.append(node.right)
            else: node.right = None
            index += 1
        
        return dummyHead

        
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
```
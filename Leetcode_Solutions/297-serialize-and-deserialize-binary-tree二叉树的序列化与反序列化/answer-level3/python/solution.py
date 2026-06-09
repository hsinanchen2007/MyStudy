### 解题思路
此处撰写解题思路

### 代码

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
        def dfs(node,output):
            if node == None:
                output += 'None,'
            else:
                output += str(node.val) + ','
                output = dfs(node.left,output)
                output = dfs(node.right,output)
            return output
        return dfs(root,'')

        
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        def build(data):
            if data[0] == 'None':
                data.pop(0)
                return None
            node = TreeNode(data[0])
            data.pop(0)
            node.left = build(data)
            node.right = build(data)
            return node
            
        data = data.split(',')
        root = build(data)
        return root

        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
```
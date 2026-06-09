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
        if not root:
            return []
        
        res = []
        cur_level = [root]
        while cur_level:
            next_level = []
            for node in cur_level:
                if node:
                    res.append(node.val)
                    next_level.append(node.left)
                    next_level.append(node.right)
                else:
                    res.append(None)  
            cur_level = next_level
            if set(cur_level) == set([None]):
                break
        return str(res).replace('None', 'null').replace(' ', '')  # 列表转成字符串
    
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if not data:
            return None
        data = data[1:-1].split(',')  # 提取出字符串中的数值(包含null)
        
        head = TreeNode(data[0])
        cur_level = [head]
        i, length = 1, len(data)
        while cur_level and i < length:
            next_level = []
            for node in cur_level:
                if node == None:
                    continue
                if data[i] != 'null':
                    node.left = TreeNode(int(data[i]))
                i += 1
                if data[i] != 'null':
                    node.right = TreeNode(int(data[i]))
                i += 1
                next_level.append(node.left)
                next_level.append(node.right)   
            cur_level = next_level
        return head

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
```
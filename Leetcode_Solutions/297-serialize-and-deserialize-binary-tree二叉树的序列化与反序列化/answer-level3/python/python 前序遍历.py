### 解题思路
此处撰写解题思路

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
        if root is None:
            return '#'
        else:
            return str(root.val)+','+self.serialize(root.left)+','+self.serialize(root.right)


        


    def deserialize(self, data):


        def buildtree(vals):
            if not vals: return None
            val = vals.pop(0)
            if val == "#":
                return None
            else:
                root = TreeNode(int(val))
                root.left = buildtree(vals)
                root.right = buildtree(vals)
            
            return root
        

        return buildtree(data.split(','))



        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
```
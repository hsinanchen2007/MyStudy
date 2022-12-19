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
        res = []
        stack = [(root, False)]
        while stack:
            node, flag = stack.pop()
            if node:
                if flag:
                    res.append(str(node.val))
                else:
                    stack.append((node.right, False))
                    stack.append((node.left, False))
                    stack.append((node, True))
            else:
                res.append("#")

        return " ".join(res)


        

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
        

        return buildtree(data.split())





# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
```
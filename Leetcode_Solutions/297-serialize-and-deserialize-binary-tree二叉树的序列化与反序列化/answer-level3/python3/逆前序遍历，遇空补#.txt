### 解题思路
此处撰写解题思路

### 代码

```python3
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
                    stack.append((node, True))
                    stack.append((node.left, False))
                    stack.append((node.right, False))
            else:
                res.append("#")

        return " ".join(res)


    def deserialize(self, data):

        def buildtree(vals):
            if not vals: return None
            val = vals.pop()
            if val == "#":
                return None
            else:
                root = TreeNode(int(val))
                root.left = buildtree(vals)
                root.right = buildtree(vals)
            
            return root
        

        return buildtree(data.split())
```
```
class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        res = []
        stack = []
        if root:
            stack.append(root)
        while stack:
            num = 0
            for i in range(len(stack)):
                n = stack.pop(0)
                if n is None:
                    res.append(n)
                else:
                    res.append(n.val)
                    stack.append(n.left)
                    stack.append(n.right)
                    if n.left:
                        num = num + 1
                    if n.right:
                        num = num + 1
            if num == 0:
                break
        return str(res).replace(' ', '').replace('None', 'null')
            
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if '[]' == data:
            return None
        d = data[1:-1].split(',')
        res = []
        j = 1
        root = TreeNode(int(d[0]))
        stack = [root]
        while stack:
            for i in range(len(stack)):
                n = stack.pop(0)
                if j>=len(d):
                    break
                if d[j] != 'null':
                    l = TreeNode(int(d[j]))
                    n.left = l
                    stack.append(l)
                j += 1                        
                if d[j] != 'null':
                    r = TreeNode(int(d[j]))
                    n.right = r
                    stack.append(r)
                j += 1
        return root
```

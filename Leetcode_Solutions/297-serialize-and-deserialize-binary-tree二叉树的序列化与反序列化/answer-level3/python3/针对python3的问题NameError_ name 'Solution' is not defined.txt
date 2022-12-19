在playground看到函数调用方式是Solution().Codec(root)，因此把类的名称修改成solution，Codec修改为一个方法。
```
class Solution:
    def Codec(self,root):
        return self.deserialize(self.serialize(root))
        
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return ''
        else:
            res = [root.val]
            stack = []
            stack.append(root.left)
            stack.append(root.right)           
            while stack:
                root = stack[0]
                del stack[0]
                if not root:
                    res.append(None)
                else:
                    res.append(root.val)
                    stack.append(root.left)
                    stack.append(root.right)
            while res[-1]==None:
                res.pop()
            return str(res)
        
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if data == '':
            return []
        else:
            Data=data[1:-1].split(',')
            Res = TreeNode(int(Data[0]))
            stack = [Res]
            i = 1
            while stack and i<len(Data):
                res = stack[0]
                del stack[0]
                if Data[i] != ' None':
                    res.left = TreeNode(int(Data[i]))
                    stack.append(res.left)
                i += 1
                if i==len(Data):
                    break
                if Data[i] != ' None':
                    res.right = TreeNode(int(Data[i]))
                    stack.append(res.right)
                i += 1
                if i==len(Data):
                    break
            return Res
```
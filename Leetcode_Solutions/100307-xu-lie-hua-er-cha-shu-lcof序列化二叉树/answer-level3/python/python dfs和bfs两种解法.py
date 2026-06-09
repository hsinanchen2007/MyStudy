观察两种解法可以发现，往往序列化时的结构是什么，反序列化时的结构也是什么，序列化的时候用了dfs，反序列化的时候也用dfs；序列化的时候用了队列，反序列化的时候也用了队列。同时，反序列化的时候都需要额外的指针index去遍历data，取出数值到所需的结构中去。data仅仅扮演着取数容器的角色，而不直接参与到结构建设中。

前序遍历做法
```
class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        res=[]
        stack=[root]
        while stack:
            node=stack.pop()
            if node:
                res.append(node.val)
                stack.append(node.right)
                stack.append(node.left)
            else:
                res.append(None)  
        return res

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        self.index=0
        def dfs(data):
            if data[self.index]==None:
                self.index+=1
                return 
            root=TreeNode(data[self.index])
            self.index+=1
            root.left=dfs(data)
            root.right=dfs(data)
            return root
        return dfs(data)


        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
```
BFS做法
```
class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        res=[]
        q=[root]
        while q:
            node=q.pop(0)
            if node:
                res.append(node.val)
                q.append(node.left)
                q.append(node.right)
            else:
                res.append(None)  
        return res

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        root=TreeNode(data[0])
        q=[root]
        index=1
        while q:
            node=q.pop(0)
            if data[index]!=None:
                node.left=TreeNode(data[index])
                q.append(node.left)
            if data[index+1]!=None:
                node.right=TreeNode(data[index+1])
                q.append(node.right)
            index+=2
        return root

        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
```


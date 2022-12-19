```python
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        res =[]
        stack = [] #must have
        if root:
            stack = [(root,False)]
        while stack:
            node,visited= stack.pop()
            if  visited:
                res.append(node.val)
            else:
                for child in node.children[::-1]:
                    stack.append([child,False])
                stack.append([node,True])
                
        return res
```
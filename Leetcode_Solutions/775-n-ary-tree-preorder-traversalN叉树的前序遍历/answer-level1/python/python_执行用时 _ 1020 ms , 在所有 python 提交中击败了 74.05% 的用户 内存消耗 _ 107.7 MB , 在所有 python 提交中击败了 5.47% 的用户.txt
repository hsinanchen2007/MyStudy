```

**递归法**
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        self.re=[]
        def bianli(root):
            if root :
                self.re.append(root.val)
                for i in root.children:
                    bianli(i)
            return self.re
        return bianli(root)
        
        
        
        
                

            
            
```

```
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""

**迭代法：**
class Solution(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        re = []
        stack=[]
        if root :
            stack.append(root)
            while stack :
                tmp = stack.pop()
                re.append(tmp.val)
                for i in reversed(tmp.children):
                    stack.append(i)
        return re
        
        
        
                

            
            
```

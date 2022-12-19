```
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: Node
        :rtype: List[List[int]]
        """
        if root is None:
            return []
        queue = [root]                                         
        out = []
        while queue:
            child = []                                          
            node = []                                         
            for item in queue:                                  
                child.append(item.val)
                if item.children: 
                    node += item.children
            out.append(child)
            queue = node                                      
        return out

```

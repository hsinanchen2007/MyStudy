```
class Solution(object):
    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        def search(Root):
            if Root:
                if Root.right == None and Root.left == None :
                    r.append(Root.val)
                search(Root.left)
                search(Root.right)
        

        r = []       
        search(root1)
        r1 = r
        r = [] 
        search(root2) 
        
        if r == r1 :
            return True
        else:
            False
```

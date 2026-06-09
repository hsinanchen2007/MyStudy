```
class Solution(object):
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        if root is None:
            return None
        
        queen = [root]
        result = []
        while queen:   
            out = []
            temp = []
            for t in queen:   
                out.append(t.val)
                if t.left:
                    temp.append(t.left)
                if t.right:
                    temp.append(t.right)
            result.append(float(sum(out)) / len(out))
            queen = temp
        return result
```

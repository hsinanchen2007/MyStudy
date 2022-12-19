
### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        if not root:
            return 0
        
        def Solutions(Root, sums):
            left = right = 0
            temp = [num + Root.val for num in sums] + [Root.val]
            if Root.left:
                left = Solutions(Root.left, temp)
            if Root.right:
                right = Solutions(Root.right, temp)
            
            return temp.count(sum) + left + right
        
        return Solutions(root, [])





            

 

```
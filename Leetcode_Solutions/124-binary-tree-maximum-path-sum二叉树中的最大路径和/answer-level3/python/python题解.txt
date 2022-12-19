### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.max_sum = float('-inf')
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        #递归方法

        def Max_path(Root):
            
            if not Root:
                return 0
            left = max(Max_path(Root.left), 0)
            right = max(Max_path(Root.right), 0)
            new_path = Root.val + left + right
            self.max_sum = max(new_path,self.max_sum)
            
            return Root.val + max(left, right)

        Max_path(root)
        return self.max_sum 

        

```
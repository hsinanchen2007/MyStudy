

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
        self.res = 0
        self.max_path = 0
    def longestUnivaluePath(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        
        #递归实现
        def LongPath(node):
            if not node:
                return 0
            left = LongPath(node.left)
            right = LongPath(node.right)
            print(self.max_path)
            if node.left and node.right:
                if node.val == node.left.val and node.val == node.right.val:
                    self.max_path = max(2 + left + right, self.max_path)
                    return 1 + max(left, right)

            if node.left:
                if node.left.val == node.val:
                    self.max_path = max(1 + left, self.max_path)
                    return 1 + left

            if node.right:
                if node.right.val == node.val:
                    self.max_path = max(1 + right, self.max_path)
                    return 1 + right
                
            return 0    

        LongPath(root)
        return self.max_path


                


            

```
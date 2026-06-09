### 解题思路
此处撰写解题思路

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
#递归，注意这道题要求的对称是结构相同，并且值也要相同
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        def new_trees(root_left,root_right):
            if root_left == None and root_right == None:
                return True
            if root_left == None or root_right ==None:
                return False  
            if root_left.val !=root_right.val:#如果只要求结构对称的话不用这一行代码
                return False
            return new_trees(root_left.left,root_right.right) and new_trees(root_left.right,root_right.left)
        return new_trees(root.left,root.right)
#DFS
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        stack  = [(root.left,root.right)]
        while stack :
            a, b = stack .pop()
            if not a and not b:
                continue
            if a and b and a.val == b.val:
                stack .append((a.left, b.right))
                stack .append((a.right,b.left))
            else:
                return False
        return True
#BFS
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        queue = deque([(root.left,root.right)])
        while queue :
            a, b = queue.popleft()
            if not a and not b:
                continue
            if a and b and a.val == b.val:
                queue.append((a.left, b.right))
                queue.append((a.right,b.left))
            else:
                return False
        return True
```
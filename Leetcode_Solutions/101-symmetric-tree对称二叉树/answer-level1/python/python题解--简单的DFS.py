### 解题思路
![image.png](https://pic.leetcode-cn.com/a7f7a01fb65db023a36327f708a8ebbecef9aa7fdb3b6bb0e0b073ee77684491-image.png)

- 思路很简单的,这题目也在剑指offer中出现过,这题目采用DFS的思路来解决
- 只需要在两个子树上判断`isSym(root1.left, root2.right) and isSym(root1.right, root2.left)`
### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        def isSym(root1, root2):
            if not root1 and not root2:
                return True
            if root1 and root2:
                if root1.val == root2.val:
                    return isSym(root1.left, root2.right) and isSym(root1.right, root2.left)
            return False
    
        return isSym(root.left, root.right)
```
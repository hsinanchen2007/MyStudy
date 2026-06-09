### 解题思路
如题

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def increasingBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        #遍历一个节点的顺序
        #有左则左，有根则根，有又则又
        result=[]
        def search(root):
            if not root:
                return
            if root.left:
                search(root.left)
            result.append(root.val)
            if root.right:
                search(root.right)
        search(root)
        if not result:
            return None
        start=TreeNode(result[0])
        res=start
        for i in result[1:]:
            start.right=TreeNode(i)
            start=start.right
        return res
            
```
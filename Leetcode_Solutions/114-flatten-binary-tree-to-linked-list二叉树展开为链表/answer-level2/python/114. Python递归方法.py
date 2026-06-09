### 解题思路
后序遍历，把左子树接在root和root.right之间。
之所以用后序遍历是因为只有当把左右子树都处理成链表的时候才能进行拼接。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """

        def get_res(root):
            if root is None:
                return 
            get_res(root.left)
            get_res(root.right)
            if root.left or root.right:
                if root.left:
                    p = root.left
                    q = root.right
                    root.left = None
                    root.right = p
                    while p.right:
                        p = p.right
                    p.right = q
                  
        get_res(root)
            
            
        
```
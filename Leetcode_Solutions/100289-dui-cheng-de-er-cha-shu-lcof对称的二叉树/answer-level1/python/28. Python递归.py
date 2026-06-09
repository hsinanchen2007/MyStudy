### 解题思路
这个问题可以看成root的左右两棵子树是否对称，更具体的，左右两棵子树的对称节点是否相同，这样我们就能写出下面代码，相当于同时遍历两棵子树。
注：剑指上给的方案也就是比较前序遍历结果和对称前序遍历结果是否相同，这种方法每个节点都要遍历两遍，但是如果同时对root两棵子树进行对称遍历判断相等每个节点只需要遍历一遍。

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
        if root is None:
            return True
        def get_res(root_1, root_2):
            if root_1 is None and root_2 is None:
                return True
            if root_1 is None and root_2 is not None or root_1 is not None and root_2 is None:
                return False
            return root_1.val == root_2.val and get_res(root_1.left, root_2.right) and get_res(root_1.right, root_2.left)
        return get_res(root.left, root.right)
        
```
### 解题思路
方法一：看到这道题的第一个思路是直接对树进行中序遍历，并记录上一个结果p和当前结果q的大小关系，如果p >= q，则返回False。思想很简单。
方法二：对树中节点值的范围进行确定，比如，如果当前节点是父亲节点的左孩子，那么当前节点的下限就是父亲节点的值，反之，当前节点的上限就是父亲节点的值，通过对当前节点值的范围是否在限制范围内来判断二叉查找树是否合法。
注：下面代码实现的是方法二，而注释掉的代码实际上在判断上下限时已经包括。


### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """

        def get_res(root, min, max):
            if root == None:
                return True
            if root.val <= min or root.val >= max:
                return False
            """
            if root.left and root.left.val >= root.val:
                return False
            if root.right and root.right.val <= root.val:
                return False
            """
            return get_res(root.left, min, root.val) and get_res(root.right, root.val, max)

        return get_res(root, float('-inf'), float('inf'))            
```
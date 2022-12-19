### 解题思路
两种思路：
注意与查询操作的区别，查询时只要找到了就直接retur随时都可以return，但插入操作会修改树本身，所以当create一个新的节点之后需要连上之前的节点，并且注意题中要求返回插入后二叉搜索树的根节点。
递归与遍历的时间空间复杂度与查询操作一样

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def insertIntoBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        if not root:
            return TreeNode(val)
        
        if val > root.val:
            # insert into the right subtree
            root.right = self.insertIntoBST(root.right, val)
        else:
            # insert into the left subtree
            root.left = self.insertIntoBST(root.left, val)
        return root



#遍历
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
       node = root
        while node:
            # insert into the right subtree
            if val > node.val:
                # insert right now
                if not node.right:
                    node.right = TreeNode(val)
                    return root
                else:
                    node = node.right
            # insert into the left subtree
            else:
                # insert right now
                if not node.left:
                    node.left = TreeNode(val)
                    return root
                else:
                    node = node.left
        return TreeNode(val)





```
### 解题思路
可以先分别获取根节点到目标节点的路径,然后求公共节点(类似于求相交链表的第一个公共节点).
遍历根节点到目标路径的过程调试了好久,没有理清出栈的条件,对栈还是不熟悉啊

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):

    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        p_path = []
        q_path = []
        self.getPath(root, p, p_path)
        self.getPath(root, q, q_path)
        res = None
        length = min(len(p_path), len(q_path))
        idx = 0
        while idx < length:
            if p_path[idx] == q_path[idx]:
                res = p_path[idx]
            idx += 1
        return res

    def getPath(self, root, p, path):
        if not root or not p:
            return False
        path.append(root)
        if root == p:
            return True
        left = self.getPath(root.left, p, path)
        right = self.getPath(root.right, p, path)
        if left or right:
            return True
        path.pop()
        
```
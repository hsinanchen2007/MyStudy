### 解题思路
基本的递归，一遍写成，一遍过，哇哈哈哈
![wakaka.png](https://pic.leetcode-cn.com/a987e11d5c612dba28eb96aa00bc9fe95a879d01dfcd11cdefb4c352e02e0d3d-wakaka.png)


### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def pathSum(self, root, s):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        def travel(root, s, tmp, ret):
            if root is None:
                return
            tmp.append(root.val)
            if sum(tmp) == s and root.left is None and root.right is None:
                ret.append(tmp[:])
            if root.left:
                travel(root.left, s, tmp, ret)
                tmp.pop(-1)
            if root.right:
                travel(root.right, s, tmp, ret)
                tmp.pop(-1)
        ret = []
        travel(root, s, [], ret)
        # print ret
        return ret

```
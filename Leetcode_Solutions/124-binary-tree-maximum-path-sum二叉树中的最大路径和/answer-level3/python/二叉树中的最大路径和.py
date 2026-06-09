### 解题思路
1、后序遍历思想，左>右>根
2、全局变量，最大路径和
3、返回左右节点最大和值，若为负数，则比路径和小

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def search(node):
            if not node: return 0
            # 右边最大值
            left = search(node.left)
            # 左边最大值
            right = search(node.right)
            # 和全局变量比较
            self.res = max(left + right + node.val, self.res)
            # >0 说明都能使路径变大
            return max(0, max(left,  right) + node.val)

        self.res = float("-inf")
        search(root)
        return self.res 


```
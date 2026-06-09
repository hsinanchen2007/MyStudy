### 解题思路
题目的意思就是：对于每个节点，求其左右两边路径加上自身值。所有节点中，最大的这个值就是输出。左右两边不用全加，只需要加正数的边。

所有在traverse过程中，更新结果和传递数据是两个不同的数：分别是下面的： self.result = max(self.result, result + left + right) 和 result + max(left, right)。

对于每个节点，其对最终结果的影响在于左右两边都考虑。但是传递给父节点的时候，只需要传递最大的一边。


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
        self.result = float("-inf")
        self.dfs(root)
        return self.result

    def dfs(self, node):
        if not node:
            return 0

        result = node.val
        left = max(self.dfs(node.left), 0)
        right = max(self.dfs(node.right), 0)
 
        self.result = max(self.result, result + left + right)
        # if result == 20 or result == 7 or result == -10:
        # print result, self.result, left, right, result + max(left, right)
        return result + max(left, right)


```
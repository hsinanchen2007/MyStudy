### 解题思路
自己写了个后序遍历的方法，提交了6次都失败，最后改了改居然成功了，自己都有点不相信。
主要想法是对于遍历到的节点，返回该节点的值、该节点与左子树的和、该节点与右子树的和三者中的最大值作为当前节点的累加最大值。另外得多保存一个，即该节点与左右子树得和。（因为有些路径不经过根节点）
最后返回所有值中的最大值。
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
        res = []
        self.search_sum(root, res)
        return max(res)

    def search_sum(self, root, res):
        if not root:
            return 0
        if not root.left and not root.right:
            res.append(root.val)
            return root.val
        left_val = self.search_sum(root.left, res)
        right_val = self.search_sum(root.right, res)
        res.append(root.val + left_val + right_val)
        temp = max(root.val, root.val + left_val, root.val + right_val)
        res.append(temp)
        return temp

        
```
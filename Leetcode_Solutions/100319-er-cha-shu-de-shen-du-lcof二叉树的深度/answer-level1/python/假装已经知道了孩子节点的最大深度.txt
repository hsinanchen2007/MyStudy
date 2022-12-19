### 解题思路
1、递归的要义，就是假装知道了孩子的最大深度；
2、那么自己的高度，就是左边孩子的高度+右边孩子的高度，两个的最大值，然后加1
3、当然，终止条件，是root为null，那么就是0；

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        
        return max(self.maxDepth(root.left), self.maxDepth(root.right))+1


```
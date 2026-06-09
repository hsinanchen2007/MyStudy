### 解题思路
1. https://leetcode-cn.com/problems/house-robber-iii/solution/san-chong-fang-fa-jie-jue-shu-xing-dong-tai-gui-hu/
解法3 的python代码
### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def robInternal(root):
            if not root: return [0] * 2;
            left, right = robInternal(root.left), robInternal(root.right)
            return [max(left) + max(right), left[0] + right[0] + root.val]

        return max(robInternal(root))
    
```
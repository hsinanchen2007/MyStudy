### 解题思路
其实就是二叉树的后序遍历，我们只需要知道对当前节点如何操作即可
这道题和[124. 二叉树中的最大路径和](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)非常类似，但是官方一个是简单一个困难！！不知道怎么定义难易程度的
![image.png](https://pic.leetcode-cn.com/ba0087883f2058aa743d1186d67f418297dde0c90a611b81e81a325c6ed2e6ad-image.png)


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def longestUnivaluePath(self, root: TreeNode) -> int:
        ans = 0
        def help(root):
            nonlocal ans
            if root is None:
                return 0 
            left = help(root.left)
            right = help(root.right)

            left_temp, right_temp = 0, 0
            if root.left and root.left.val == root.val:
                left_temp = left + 1
            if root.right and root.right.val == root.val:
                right_temp = right + 1
            ans = max(ans, left_temp + right_temp)
            return max(left_temp, right_temp)

        help(root)
        return ans
            


            
                

```
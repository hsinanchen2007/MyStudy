### 解题思路
根据二叉搜索树的性质可知，对它进行中序遍历可以得到一个单调递增数组，这样一来，最小绝对差一定等于当前值与前一值的差。
使用迭代法（用栈实现）实现二叉搜索树的中序遍历，然后使用pre和cur两个变量分别储存上一状态值和当前值，使用res储存当前所能得到的最小绝对差。

时间复杂度：O(n)，遍历二叉搜索树一遍即可
空间复杂度：O(n)，主要用于栈的空间实现
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
        res=float('inf')
        pre=float('-inf')
        stack=[]
        node=root
        while node or stack:
            if node:
                stack.append(node)
                node=node.left
            else:
                node=stack.pop()
                cur=node.val
                res=min(cur-pre,res)
                pre=cur
                node=node.right
        return res
```
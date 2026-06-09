### 解题思路
深度遍历整个二叉树
1.从根节点开始遍历，设置一个局部变量保存当前遍历整数。
2.节点每往下面移动一次，局部变量乘以十并加上当前值
3.设置一个全局变量，遇到叶节点将当前局部变量值加入全局变量

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        #deep ergodic
        self.res = 0
        if root == None:return 0
        def helper(node,cur):
            if node.left:
                helper(node.left,cur*10+node.val)
            if node.right:
                helper(node.right,cur*10 + node.val)
            if node.left == None and node.right == None:
                self.res += cur*10+node.val
        helper(root,0)
        return self.res


```
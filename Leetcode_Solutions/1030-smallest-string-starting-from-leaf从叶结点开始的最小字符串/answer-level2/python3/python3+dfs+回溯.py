### 解题思路
dfs+回溯

![UC截图20200106111318.png](https://pic.leetcode-cn.com/25cb9064dd9212431e00c032933d01d2fba7df3cfa9f91b8e678c4bce897ff64-UC%E6%88%AA%E5%9B%BE20200106111318.png)


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.min_str = 'z'*14
        self.res = ''

    def smallestFromLeaf(self, root: TreeNode) -> str:
        def help(root):
            if not root.left and not root.right:
                self.min_str = min(self.min_str,self.res[::-1])
            if root.left:
                self.res += chr(97 + root.left.val)
                help(root.left)
            if root.right:
                self.res += chr(97 + root.right.val)
                help(root.right)
            self.res = self.res[:-1]
        if not root:
            return ''
        self.res += chr(97 + root.val)
        help(root)
        return self.min_str
```
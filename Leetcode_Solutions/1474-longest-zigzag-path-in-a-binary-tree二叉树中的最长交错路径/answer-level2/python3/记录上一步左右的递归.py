### 解题思路
此处撰写解题思路
简单递归，代码如下

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def length(self, root, max_length, direct):
        # print(max_length)
        self.re = max(self.re, max_length)
        if not root.left and not root.right:
            return
        if root.left :
            if direct == 'left':
                new_max_length = 1
                self.length(root.left, new_max_length, 'left')
            else:
                new_max_length = 1 + max_length
                self.length(root.left, new_max_length, 'left')
            # max_length = 0

        if root.right:
            if direct == 'left':
                new_max_length = max_length + 1
                self.length(root.right, new_max_length, 'right')
            else :
                new_max_length = 1
                self.length(root.right, new_max_length, 'right')
            # max_length = 0
    def longestZigZag(self, root: TreeNode) -> int:
        self.re = 0
        max_length = 0
        self.length(root, max_length, 'left')

        # max_length = 0
        # self.length(root, max_length, 'right')
        # print('haha')

        return self.re


        
```
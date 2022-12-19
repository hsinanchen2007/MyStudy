### 解题思路
此处撰写解题思路
1. 深度遍历整个树，每遍历一层，值为：当前节点值+10倍之前的值；
2. 构造一个可传函数值变量：当树的左、右节点都为空时返回结果；
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
        if root == None:
            return 0
        def help(root, val, result):
            if root == None:
                return
            val = 10*val + root.val
            if not root.left and not root.right:
                result.append(val + result[-1])
                return
            if root.left:
                help(root.left, val, result)
            if root.right:
                help(root.right, val, result)
            
        val = 0
        result = [0]
        help(root, val, result)
        return result[-1]
        
            
```
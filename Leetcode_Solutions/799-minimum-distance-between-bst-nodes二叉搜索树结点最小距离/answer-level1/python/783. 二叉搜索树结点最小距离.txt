### 解题思路
中序遍历， 不断比较当前节点和上一个节点差值即可（递归and迭代）
![image.png](https://pic.leetcode-cn.com/a1318d5ea6d44d7b7a781c0845df0198a09492b63dbd7a497ea6a2264edfd210-image.png)


### 代码（递归版本）

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        res = float('inf')
        pre = None
        def help(root):
            nonlocal res, pre
            if root is None:
                return
            
            help(root.left)
            
            if pre is not None:
                temp = root.val - pre.val
                res = min(res, temp)
            pre = root

            help(root.right)
        help(root)
        return res
```
### 代码（迭代版本）
``` python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        res = float('inf')
        pre = None

        stack = []
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            
            if pre is not None:
                temp = root.val - pre.val
                res = min(res, temp)
            pre = root

            root = root.right
        return res
```
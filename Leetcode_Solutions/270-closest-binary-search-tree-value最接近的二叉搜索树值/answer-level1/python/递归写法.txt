
    基本思路就是：二叉搜索树的有一个  左结点<父结点<右结点  的规律。所以不需要遍历整棵树，只需要遍历一条分支即可。这里我使用了一个dict进行存储difference和node.value

--------------
##### 我的解法：

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def closestValue(self, root: TreeNode, target: float) -> int:
        values = {}
        def inner(root, target):
            if not root:
                min_key = min(values.keys())
                return values[min_key]
    
            values[abs(target-root.val)] = root.val
            
            if target == root.val:
                return root.val

            if target > root.val:
                a = inner(root.right, target)
                return a
            if target < root.val:
                b = inner(root.left, target)
                return b
            
        return inner(root, target)
```
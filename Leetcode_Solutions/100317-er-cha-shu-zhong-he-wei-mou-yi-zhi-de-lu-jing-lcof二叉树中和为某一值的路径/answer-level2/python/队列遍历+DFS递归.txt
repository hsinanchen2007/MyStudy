
### 队列遍历
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def pathSum(self, root: TreeNode, target: int) -> List[List[int]]:
        if not root:return []
        stack = [(root,[root.val])]
        res = []
        while stack:
            node , val = stack.pop()
            if node.right:stack.append((node.right, val+[node.right.val]))
            if node.left: stack.append((node.left,val+[node.left.val]))
            if node and not node.left and not node.right and sum(val) == target:res.append(val)
        return res
```
### DFS 递归
```
class Solution:
    def pathSum(self, root: TreeNode, target: int) -> List[List[int]]:
        res = init = []
        def helper(path, cur, root):
            if not root:return
            path,cur = path+[root.val], cur+root.val
            if root.left:helper(path, cur, root.left)
            if root.right:helper(path, cur, root.right)
            if not root.left and not root.right and cur==target:res.append(path)
        helper(init,0,root)
        return res
```

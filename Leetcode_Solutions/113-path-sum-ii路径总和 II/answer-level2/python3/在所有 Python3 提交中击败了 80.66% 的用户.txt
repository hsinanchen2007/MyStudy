### 解题思路
用dfs，兄弟们
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
         
        if root is None:
            return []

        res_left = []
        res_right = []
        reach = sum - root.val
        if reach == 0 and root.left == None and root.right == None:
            return [[root.val]]        
        if root.left != None:
            self.dfs(root.left,reach,[root.val],res_left)
        if root.right is not None:
            self.dfs(root.right,reach,[root.val],res_right)
        return res_left + res_right

    def dfs(self,root,target,memo, res):
        if target - root.val == 0 and root.left == None and root.right == None:
            memo.append(root.val)
            res.append(memo[:])
        else:
            memo.append(root.val)
            if root.left != None:
                self.dfs(root.left,target - root.val,memo[:],res)
            if root.right != None:
                self.dfs(root.right,target-root.val,memo[:],res)

            return res
```
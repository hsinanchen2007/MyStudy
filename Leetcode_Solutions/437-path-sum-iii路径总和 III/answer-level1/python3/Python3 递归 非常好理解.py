执行结果：通过 显示详情
执行用时: 384 ms, 在所有 Python3 提交中击败了60.96%的用户
内存消耗: 14.9 MB, 在所有 Python3 提交中击败了21.36%的用户

### 解题思路
左递归 右递归 返回所有路径和

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, target: int) -> int:
        def find(node, target):
            if not node:
                return ([], 0) # [path_sum], count
            
            l_ps, l_count = find(node.left, target)
            r_ps, r_count = find(node.right, target)
            path_sum = [ps + node.val for ps in l_ps + r_ps] + [node.val]
            count = l_count + r_count
            for ps in path_sum:
                if ps == target:
                    count += 1
            return (path_sum, count)
        
        return find(root, target)[1]
```
### 解题思路
执行用时 :56 ms, 在所有 Python3 提交中击败了40.80%的用户
内存消耗 :15.5 MB, 在所有 Python3 提交中击败了5.17%的用户

注意叶子结点的概念！
if not r.left and not r.right：
    balabala
所以[1, 2] 1 -> False 而 [1] 1 -> True

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum_: int) -> bool:
        
        def dfs(r, cnt):
            if not r:
                return False
            
            if not r.left and not r.right:  # 叶子节点
                if cnt == sum_ - r.val:
                    return True
                else:
                    return False
                
            return dfs(r.left, cnt+r.val) or dfs(r.right, cnt+r.val)
            
        return dfs(root, 0)
```
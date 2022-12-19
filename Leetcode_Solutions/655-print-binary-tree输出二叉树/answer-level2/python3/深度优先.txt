### 解题思路
第一步求出树的高度；
第二步根据树的高度求出二维数组；
第三步根据树的节点更改二维数组。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def printTree(self, root: TreeNode) -> List[List[str]]:
        def depth(root):
            if not root:
                return 0
            left = depth(root.left)
            right = depth(root.right)
            return 1 + max(left, right)

        m = depth(root)
        n = 2 ** m - 1
        res = [[""] * n for _ in range(m)]
        
        def dfs(root, depth, start, end):
            if not root:
                return
            mid = start + (end - start) // 2
            res[depth][mid] = str(root.val)
            dfs(root.left, depth + 1, start, mid - 1)
            dfs(root.right, depth + 1, mid + 1, end)
        
        dfs(root, 0, 0, n)
        return res
```
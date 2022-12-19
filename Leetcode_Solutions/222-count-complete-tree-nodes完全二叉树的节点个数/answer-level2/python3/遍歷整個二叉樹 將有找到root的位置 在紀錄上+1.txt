### 解题思路
遍歷整個二叉樹 
將有找到root的位置 
在紀錄上+1

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def countNodes(self, root: TreeNode) -> int:
        count = 0
        def search(root):
            nonlocal count
            if not root:
                return
            count += 1
            search(root.left)
            search(root.right)
        search(root)
        return count    

```
### 解题思路
有三种情况：
1. 当上下关系不同时，则返回[-1]；
2. 同层左右节点时，添加他们的父节点到返回的列表里，交换左右节点；
3. 当相同时，继续往下遍历；

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flipMatchVoyage(self, root: TreeNode, voyage: List[int]) -> List[int]:
        self.i = 0
        self.flipped = []
        
        def dfs(node):
            if not node:
                return
            if node.val != voyage[self.i]:
                self.flipped = [-1]
                
            self.i += 1
            if self.i < len(voyage) and node.left and node.left.val != voyage[self.i]:
                self.flipped.append(node.val)
                dfs(node.right)
                dfs(node.left)
            else:
                dfs(node.left)
                dfs(node.right)
        dfs(root)
        return [-1] if self.flipped and self.flipped[0] == -1 else self.flipped
```
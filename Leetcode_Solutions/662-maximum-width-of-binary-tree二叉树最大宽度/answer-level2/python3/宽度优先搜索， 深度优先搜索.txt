### 解题思路
最重要是要知道最左边和最右边的索引，这样 右边索引 - 左边索引 + 1，即是每层的宽度；
那最左边索引和上层父节点索引之间的关系是2 * pos，右边的索引是父节点索引 2 * pos + 1
1. 宽度优先搜索
2. 深度优先搜索， lefts保存了每一层最左边的索引位置，这样同一层的

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# 方法一： 宽度优先搜索
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        q = [(root, 0, 0)]
        curr_depth = left = res = 0
        for node, depth, pos in q:
            if node:
                q.append((node.left, depth + 1, pos * 2))
                q.append((node.right, depth + 1, pos * 2 + 1))
                if curr_depth != depth:
                    curr_depth = depth
                    left = pos
                res = max(pos - left + 1, res)
        return res

# 方法二： 深度优先搜索
    def widthOfBinaryTree(self, root):
        lefts = {}
        self.res = 0
        def dfs(root, depth=0, pos=0):
            if not root:
                return
            lefts.setdefault(depth, pos)
            self.res = max(self.res, pos - lefts[depth] + 1)
            dfs(root.left, depth + 1, pos * 2)
            dfs(root.right, depth + 1, pos * 2 + 1)
        
        dfs(root)
        return self.res
```
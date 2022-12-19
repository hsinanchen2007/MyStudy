### 解题思路
定义一个列表，存储二叉树的每个节点和深度，过程中持续更新最大深度
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root: return 0
        dnode = [[root, 1]]
        i = 0
        max_deep = 1
        while i < len(dnode):
            child = False
            cur = dnode[i]
            if cur[0].left:
                dnode.append([cur[0].left, cur[1]+1])
                child = True
            if cur[0].right:
                dnode.append([cur[0].right, cur[1]+1])
                child = True
            if child:
                max_deep = cur[1]+1
            i += 1
        return max_deep
```
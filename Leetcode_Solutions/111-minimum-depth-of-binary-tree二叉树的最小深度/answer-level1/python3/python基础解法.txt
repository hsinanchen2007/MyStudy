### 解题思路
1. BFS，广度优先搜索的时候顺便存储depth，通过判断只要有一个node没有子节点，就直接输出depth
2. DFS，深度优先搜索的时候存储depth，但是需要注意，随时替换最小的depth
3. 递归其实也是利用的dfs的思想

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        # if not root:
        #     return 0
        # queue = [(1, root)]
        # while current_level:
        #     depth, root = queue.pop(0)
        #     next_level = [root.left, root.right]
        #     if not any(next_level):
        #         return depth
        #     for i in next_level:
        #         if i:
        #             queue.append((depth+1, i))

        # if not root:
        #     return 0
        # else:
        #     stack, min_depth = [(1, root)], float('inf')
        
        # while stack:
        #     depth, root = stack.pop()
        #     next_root = [root.left, root.right]
        #     if not any(next_root):
        #         min_depth = min(depth, min_depth)
        #     for i in next_root:
        #         if i:
        #             stack.append((depth+1, i))
        # return min_depth

        if not root:
            return 0
        else:
            current_root = [root.left, root.right]
        
        if not any(current_root):
            return 1
        
        min_depth = float('inf')
        for i in current_root:
            if i:
                min_depth = min(self.minDepth(i), min_depth)
        return min_depth+1


```
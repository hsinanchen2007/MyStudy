### 解题思路
深度优先搜索的简单应用，书写的时候可以使用collections一些方便的数据结构来简化代码。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        
        result = collections.defaultdict(list)
        queue = collections.deque()

        queue.append((0,root))
        while queue:
            level, node = queue.popleft()
            if node:
                result[level].append(node.val)
                queue.append((level+1, node.left))
                queue.append((level+1, node.right))
        
        return [sum(x)/len(x) for x in result.values()]
        
```
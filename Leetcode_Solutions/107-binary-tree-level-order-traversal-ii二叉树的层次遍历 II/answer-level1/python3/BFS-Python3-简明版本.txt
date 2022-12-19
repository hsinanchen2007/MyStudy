### 解题思路
使用defaultdict和deque使代码稍微简洁一些。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []

        stored = collections.defaultdict(list)
        queue = collections.deque()

        queue.append([0,root])

        while queue:
            level, node = queue.popleft()
            stored[level].append(node.val)
            if node.left:
                queue.append([level+1, node.left])
            if node.right:
                queue.append([level+1, node.right])
        
        return [stored[i] for i in reversed(range(len(stored)))]
        

```
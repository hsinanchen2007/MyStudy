- 使用deque感觉更自然一点
 
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
        ans = []
        from collections import deque
        de = deque()
        de.append(root)
        while de:
            x = []
            #多个子节点，使用循环
            for _ in range(len(de)):
                child = de.popleft()
                x.append(child.val)
                if child.left:
                    de.append(child.left)
                if child.right:
                    de.append(child.right)
            ans.append(x)
        ans.reverse()
        return ans
```
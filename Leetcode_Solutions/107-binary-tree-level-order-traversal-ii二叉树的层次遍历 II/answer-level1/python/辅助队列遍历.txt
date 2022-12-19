### 解题思路
此处撰写解题思路

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
        levels = []
        from collections import deque
        q = deque()
        pos = root
        if pos:
            levels.append([pos.val])
        if pos.left:
            q.append(pos.left)
        if pos.right:
            q.append(pos.right)
        nums = []
        temp_q = deque()
        while q.__len__():
            pos = q.popleft()
            nums.append(pos.val)
            if pos.left:
                temp_q.append(pos.left)
            if pos.right:
                temp_q.append(pos.right)
            
            if not q.__len__():
                levels.append(nums)
                nums = []
                while temp_q.__len__():
                    q.append(temp_q.popleft())
        if nums:
            levels.append(nums)
        return levels[::-1]






```
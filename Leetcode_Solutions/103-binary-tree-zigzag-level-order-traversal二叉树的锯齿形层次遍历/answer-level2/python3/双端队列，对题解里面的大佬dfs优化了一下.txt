### 解题思路
时间击败百分之99
内存百分之100
主要是使用双端队列，不然使用列表的话每次insert都是O(N)
对题解里面大佬dfs版本的优化
我自己做的话更倾向于bfs，bfs做的太多了，所以尝试练习一下dfs
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        # dfs
        res = deque()
        def helper(root, depth):
            if not root: return 
            if len(res) == depth:
                # 使用双端队列
                res.append(deque())
            # 奇偶判断
            if depth % 2 == 0:res[depth].append(root.val)
            else: res[depth].appendleft(root.val)
            helper(root.left, depth + 1)
            helper(root.right, depth + 1)
        helper(root, 0)
        return res
```
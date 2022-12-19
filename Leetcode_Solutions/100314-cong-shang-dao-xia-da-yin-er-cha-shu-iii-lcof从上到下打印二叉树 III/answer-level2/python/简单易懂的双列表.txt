### 解题思路

额外用一个列表进行存储。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root: return []
        queue = [root]
        res = []
        while queue:
            temp = []
            helper_queue = []
            for i in queue:
                temp.append(i.val)
                if i.left: helper_queue.append(i.left)
                if i.right: helper_queue.append(i.right)
            res.append(temp)
            queue = helper_queue
        for i, j in enumerate(res):
            if i % 2 != 0: res[i].reverse()
        return res

```
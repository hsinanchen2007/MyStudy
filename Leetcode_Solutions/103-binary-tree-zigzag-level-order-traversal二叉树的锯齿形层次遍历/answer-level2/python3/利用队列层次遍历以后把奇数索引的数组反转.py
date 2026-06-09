### 解题思路
层次遍历以后把奇数索引的数组反转

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        else:
            res = []
            queue = [root]
            while queue:
                temp = []
                size = len(queue)
                for i in range(size):
                    r = queue.pop(0)
                    temp.append(r.val)
                    if r.left:
                        queue.append(r.left)
                    if r.right:
                        queue.append(r.right)
                res.append(temp)
            if len(res) < 2:
                return res
            else:
                for i in range(1,len(res),2):
                    res[i] = res[i][::-1]
                return res







```
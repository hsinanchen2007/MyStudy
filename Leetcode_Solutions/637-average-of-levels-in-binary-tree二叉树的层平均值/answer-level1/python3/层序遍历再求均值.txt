### 解题思路
层序遍历再求均值

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
        if not root:
            return []
        else:
            res=[]
            queue = [root]
            while queue:
                temp=[]
                size = len(queue)
                for i in range(size):
                    r = queue.pop(0)
                    temp.append(r.val)
                    if r.left:
                        queue.append(r.left)
                    if r.right:
                        queue.append(r.right)
                res.append(temp)
            for i in range(len(res)):
                res[i] = sum(res[i]) / len(res[i])
            return res
            







```
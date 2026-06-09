### 解题思路
层序遍历的变形，把每一层节点存起来求平均值，加到答案的列表里面

### 代码
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        res=[]
        deque=collections.deque()
        deque.append(root)
        while deque:
            count=len(deque)
            tmp=[]
            for i in range(count):
                node=deque.popleft()
                tmp.append(node.val)
                if node.left:
                    deque.append(node.left)
                if node.right:
                    deque.append(node.right)
            res.append(sum(tmp)/count)
        return res
```

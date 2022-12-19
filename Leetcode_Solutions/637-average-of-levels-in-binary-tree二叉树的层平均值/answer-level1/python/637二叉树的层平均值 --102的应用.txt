### 解题思路
这是102二叉树的层次遍历的应用，和<103>一样引入temp辅助变量保存每层结果，并从statistics标准库中导入求均值的方法mean()

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
        #102二叉树层次遍历的应用(和103一样引入辅助变量保存每层结果)
        from collections import deque
        from statistics import mean
        queue=deque()
        queue.append(root)
        res=[]
        level=0
        while queue:
            temp=[]
            level_len=len(queue)
            for i in range(level_len):
                curNode=queue.popleft()
                temp.append(curNode.val)
                if curNode.left:
                    queue.append(curNode.left)
                if curNode.right:
                    queue.append(curNode.right)
            res.append(mean(temp))
        return res
```
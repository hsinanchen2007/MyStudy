### 解题思路
与官方题解2略有不同，仍使用广度优先搜索，但未使用temp临时数组，而只使用了一个队列queue，并使用count变量来判断是否到达每层末尾。

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
        res=[]
        queue=[root]
        length=1
        count=1
        total=0
        while queue:
            node=queue.pop(0)
            total+=node.val
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
            count-=1
            if count==0:
                ave=total/length
                res.append(ave)
                length=len(queue)
                count=length
                total=0
        return res

```
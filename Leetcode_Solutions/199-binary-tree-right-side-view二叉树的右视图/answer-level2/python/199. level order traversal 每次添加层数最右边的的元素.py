### 解题思路
层次遍历，添加最右边的元素

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        queue = []
        if root:
            queue.append(root)
        totalAns = []
        while queue != []:
            levelAns = []
            levelSize = len(queue)
            for i in range(0,levelSize):
                cur = queue[0]
                levelAns.append(cur.val)
                queue.pop(0)
                if cur.left:
                    queue.append(cur.left)
                if cur.right:
                    queue.append(cur.right)
            totalAns.append(levelAns[-1])
        return totalAns

```
### 解题思路
parent表示当前层的节点，child表示下一层节点。设置两个队列的目的用于区分每层的边界

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        if root is None:
            return []
        
        result = []
        parent = []
        parent.append(root)
        child = []
        sum = 0
        count = 0

        while len(parent) != 0:
            tmp = parent.pop(0)
            sum += tmp.val
            count += 1
        
            if tmp.left:
                child.append(tmp.left)
            if tmp.right:
                child.append(tmp.right)

            if len(parent) == 0:
                result.append(float(sum)/count)
                sum = 0
                count = 0
                parent = child
                child = []

        return result
```
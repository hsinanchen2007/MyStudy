### 解题思路
层次遍历解决问题

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def deepestLeavesSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        queue = []
        if root == None:
            return 0
        
        queue.append(root)
        ret = 0

        while len(queue) > 0:
            tmpQ = []
            ret = 0
            for n in  queue:
                ret += n.val
                if n.left != None:
                    tmpQ.append(n.left)
                if n.right != None:
                    tmpQ.append(n.right)
            
            queue = tmpQ
        
        return ret
```
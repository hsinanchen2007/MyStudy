### 解题思路
此处撰写解题思路

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        queue=[root,]
        levels=[]
        level=0
        if not root:
            return levels
        while queue:
            flag=0
            n=len(queue)
            for i in range(n):
                node=queue.pop(0)
                if flag==0:
                    levels.append(node.val)
                    flag+=1
                else:
                    levels[level]=max(levels[level],node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            level+=1
        return levels
        
      

```
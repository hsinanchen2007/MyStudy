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
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        stack=[]
        ans=65536*2-1
        now=root
        tmp=None
        while stack or now:
            while now :
                stack.append(now)
                now=now.left
            if tmp!=None:
                ans=min(ans,abs(tmp.val-stack[-1].val))
            tmp=stack.pop()
            now=tmp
            now=now.right
        return ans
        
```
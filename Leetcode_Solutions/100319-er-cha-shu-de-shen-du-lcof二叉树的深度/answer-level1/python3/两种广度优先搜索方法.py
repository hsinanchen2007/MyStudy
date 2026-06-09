### 解题思路
利用广度优先搜索，当stack为[]时，表示遍历完所有层

### 代码1

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        
        stack=[[root,1]]
        deep=0 
        while stack:
            [node,level]=stack.pop()
            deep=max(deep,level)
            if node.left:
                stack.append([node.left,level+1])
            if node.right:
                stack.append([node.right,level+1])         
        return deep
```
### 代码2
```
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0 
        stack=[[root,1]]
        deep=0
        while stack:
            temp=[]
            for [node,level] in stack:
                deep=max(deep,level)
                if node.left:
                    temp.append([node.left,level+1])
                if node.right:
                    temp.append([node.right,level+1])
            stack=temp
        return deep
```

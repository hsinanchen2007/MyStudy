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
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        def dfs(root,path,paths):
            path+=str(root.val)
            if root.left==None and root.right==None:
                paths.append(path)
                return
            if root.left!=None:
                dfs(root.left,path+"->",paths)
            if root.right!=None:
                dfs(root.right,path+"->",paths)    
        paths=[]
        if root==None:
            return paths
        dfs(root,"",paths)
        return paths
```
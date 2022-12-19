### 解题思路
直接上代码

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """ 
        
        return self.nodenumber(root, 0, [])     

    def nodenumber(self, root, depth, ans):
        if not root:
            return ans
        if len(ans) == depth:
            ans.insert(0,[])
        ans[-(depth+1)].append(root.val)
        self.nodenumber(root.left, depth+1,ans)
        self.nodenumber(root.right, depth+1, ans)  
        return ans 

```
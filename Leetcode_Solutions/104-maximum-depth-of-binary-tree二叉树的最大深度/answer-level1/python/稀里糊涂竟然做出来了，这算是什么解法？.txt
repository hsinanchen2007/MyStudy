### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

def countDepth(left,right,i):
    global res
    if left==right==None:
        res.append(i)  
        return 
    if left==None and right!=None:
        countDepth(right.left,right.right,i+1)
    elif left!=None and right==None:
        countDepth(left.left,left.right,i+1)
    elif left!=None and right!=None:
        countDepth(right.left,right.right,i+1)
        countDepth(left.left,left.right,i+1)
      
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root==None:
            return 0
        global res
        res=[]
        countDepth(root,root,0)
        return max(res)
        
```
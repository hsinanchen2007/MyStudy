### 解题思路
此处撰写解题思路
唯一比较郁闷的是开始写的是
class Solution(object):
    def minDiffInBST(self, root,father=2000):
        if root is None :
            return 
        elif father is 2000 :
          diff=2000
        else    :
          diff=abs(father-root.val
       return min(diff,self.minDiffInBST(root.left,root.val),self.minDiffInBST(root.right,root.val))
结果最后报错不能用none和int比较。。
那就只有算一个入边一个一个的来。


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    res =  99999
    father= -99999
    def minDiffInBST(self, root: TreeNode):
            def dfs(root):
                if root is None :
                  return
                dfs(root.left)
                self.res=min(self.res,abs(root.val-self.father))
                self.father=root.val
                dfs(root.right)
            dfs(root)
            return self.res
                
                
       
      

```
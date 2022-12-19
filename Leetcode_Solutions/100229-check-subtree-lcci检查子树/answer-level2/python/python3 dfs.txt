### 解题思路
先找t1中t2结点
找到后进行dfs，确认子树和t2的子树完全相同，否则返回FALSE

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def checkSubTree(self,t1,t2):
        #开始递归
        if t1 == None:
            return False
        if t2 == None:
            return True
        return self.dfs(t1,t2) or self.checkSubTree(t1.left,t2) or self.checkSubTree(t1.right,t2)
    
    def dfs(self,t1,t2):
        if not t1 and t2 :
            #t1没了，t2还有
            return False
        if not t2 and not t1:
            return True
        if t1.val != t2.val:
            return False
        else:
            return self.dfs(t1.left,t2.left) and self.dfs(t1.right,t2.right)


```
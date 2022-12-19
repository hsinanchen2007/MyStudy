```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def printTree(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[str]]
        """
        
        self.max_deep=0
        '''find the depth'''
        def findDepth(node,deep):
            if not node:return
            if deep>self.max_deep:
                self.max_deep=deep
            findDepth(node.left,deep+1)
            findDepth(node.right,deep+1)
        
        findDepth(root,1)
        
        '''width'''
        width=2**self.max_deep-1
        
        '''init'''
        res=[['']*width for i in range(self.max_deep)]
        
        '''preorder and insert'''
        def pfs(node,deep,start,end):
            if not node or start>end:
                return 
            insert=start+(end-start)//2
            res[deep-1][insert]=str(node.val)
            pfs(node.left,deep+1,start,insert-1)
            pfs(node.right,deep+1,insert+1,end)
        pfs(root,1,0,width)
        return res
            
```
暴力解不过好像没有特别快的解法
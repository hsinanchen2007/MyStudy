### 解题思路
BFS和DFS的运行时间和内存差不多额...

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rangeSumBST(self, root, L, R):
        """
        :type root: TreeNode
        :type L: int
        :type R: int
        :rtype: int
        """
        if root==None:
            return 0
        summation=0
        tmp=[[root]]
        while tmp:
            s=tmp.pop()
            tmp1=[]
            for i in range(len(s)):
                if s[i].val<=R and s[i].val>=L:
                    summation+=s[i].val
                if s[i].left!=None:
                    tmp1.append(s[i].left)
                if s[i].right!=None:
                    tmp1.append(s[i].right)
            if tmp1!=[]:
                tmp.append(tmp1)
        return summation

```
### 解题思路
分别使用广度优先搜索和深度优先搜索（递归方法）

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
        #判断特殊情况
        if not root:return 0

        #广度优先方法1
        # stack=[[root,1]]
        # out=0
        # while stack:
        #     temp=[]
        #     for [node,level] in stack:
        #         if L<=node.val<=R:
        #             out=out+node.val
        #         if node.left:temp.append([node.left,level+1])
        #         if node.right:temp.append([node.right,level+1])
        #     stack=temp
        # return out

        #广度优先方法2
        # stack=[[root,1]]
        # out=0
        # while stack:
        #     [node,level]=stack.pop()
        #     if L<=node.val<=R:out+=node.val
        #     if node.left:stack.append([node.left,level+1])
        #     if node.right:stack.append([node.right,level+1])
        # return out

        #深度优先方法、递归
        # node=root
        # if node.val<L:
        #     return self.rangeSumBST(node.right,L,R)
        # if node.val>R:
        #     return self.rangeSumBST(node.left,L,R)
        # if L<=node.val<=R:
        #     return node.val+self.rangeSumBST(node.right,L,R)+self.rangeSumBST(node.left,L,R)
```
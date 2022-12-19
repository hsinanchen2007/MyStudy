### 解题思路
DFS 不断向下遍历到叶子节点，然后逐层返回，跟精选题解思路差不多

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sufficientSubset(self, root: TreeNode, limit: int) -> TreeNode:
        self.Limit = limit
        
        answer = self.DFS(root,0)
        if answer == 0:
            return None
        return(root)

    def DFS(self,Node,sums):
        sums+=Node.val
        if Node.left==None and Node.right==None:#到达根节点
            if sums <self.Limit:
                return 0
            else:
                return 1
        
        tempS = 0
        b = 0
        a = 0
        if Node.left!=None:
            a=self.DFS(Node.left,sums)
            if a ==0:
                Node.left = None
        if Node.right!=None:
            b=self.DFS(Node.right,sums)
            if b ==0:
                Node.right = None
        tempS +=(a+b)
        return tempS

```
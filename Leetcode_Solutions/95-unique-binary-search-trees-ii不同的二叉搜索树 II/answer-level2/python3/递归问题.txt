### 解题思路
记录，此为递归，每次递归返回的是一个列表，保存了以此为树的所有可能性

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        if n==0:
            return []
        def gemerate_tree(start,end):
            
            if start>end:
                return [None]
            all_tree=[]
            for i in range(start,end+1):
                left = gemerate_tree(start,i-1)
                right=gemerate_tree(i+1,end)
                for l in left:
                    for r in right:
                        root = TreeNode(i)
                        root.left=l
                        root.right=r
                        all_tree.append(root)
            return all_tree
        return gemerate_tree(1,n)





```
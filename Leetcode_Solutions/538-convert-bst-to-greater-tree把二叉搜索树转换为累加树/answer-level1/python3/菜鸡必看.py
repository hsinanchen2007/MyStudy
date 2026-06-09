### 解题思路
这递归写的好丑啊 

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        # 先返回一个递增数组 然后暴力比较
        res=[]
        def inT(root) :
            if not root :
                return 
            inT(root.left)
            res.append(root.val)
            inT(root.right)
        inT(root)
        def addT(root) :
            if not root :
                return 
            i=res.index(root.val)
            root.val+=sum(res[i+1:])
            addT(root.left)
            addT(root.right)
        addT(root)
        return root


```
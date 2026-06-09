### 解题思路
DFS

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        res=[]
        if not root:
            return []

        def dfs(root,tmpsum,tmp):
            if not root.left and not root.right:
                tmpsum+=root.val
                if tmpsum==sum:
                    tmp.append(root.val)
                    res.append(tmp[:])
                    tmp.pop()
                tmpsum-=root.val
                return
            tmpsum=tmpsum+root.val
            tmp.append(root.val)
            if root.left:
                dfs(root.left,tmpsum,tmp)
            if root.right:
                dfs(root.right,tmpsum,tmp)
            tmpsum=tmpsum-root.val
            tmp.pop()
        dfs(root,0,[])
        return res
```
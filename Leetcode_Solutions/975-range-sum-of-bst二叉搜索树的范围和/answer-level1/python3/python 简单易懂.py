搜索树中序遍历是一个排序数组，之后取范围内的数字相加即可。

```
class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        def dfs(root):
            if not root:
                return    
            dfs(root.left)
            res.append(root.val)
            dfs(root.right)
        res=[]
        dfs(root)
        
        total=0
        for i in res:
            if L<=i<=R:
                total+=i
        return total
```

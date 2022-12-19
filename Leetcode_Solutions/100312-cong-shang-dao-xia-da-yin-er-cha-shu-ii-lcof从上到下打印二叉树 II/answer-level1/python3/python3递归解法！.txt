**看此题的朋友不妨看看上一题我的题解，同样的代码，只是最后少了extend！**
```
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        res=[]
        if not root: return 
        def dfs(node,level):
            if not node: return 
            if len(res)==level:
                res.append([])
            res[level].append(node.val)
            dfs(node.left,level+1)
            dfs(node.right,level+1)
        dfs(root,0)
        return res()
```

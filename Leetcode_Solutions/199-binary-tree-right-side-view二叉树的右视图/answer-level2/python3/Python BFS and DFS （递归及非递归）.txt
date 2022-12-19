
BFS:

```
def rightSideView(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        res={}
        queue=[(root,0)]
        while queue:
            cur,level=queue.pop(0)
            res[level]=cur.val
            if cur.left:
                queue.append((cur.left,level+1))
            if cur.right:
                queue.append((cur.right,level+1))
        return list(res.values())
```




DFS递归:

```
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        
        def right(root,level):
            if not root:
                return 
            res[level]=root.val
            right(root.left,level+1)
            right(root.right,level+1)
        
        res={}
        right(root,0)
        return list(res.values())
```





DFS 非递归:

```
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        res={}
        stack=[(root,0)]
        while stack:
            cur,level=stack.pop()
            res[level]=cur.val
            if cur.right:
                stack.append((cur.right,level+1))
            if cur.left:
                stack.append((cur.left,level+1))
        return list(res.values())
```

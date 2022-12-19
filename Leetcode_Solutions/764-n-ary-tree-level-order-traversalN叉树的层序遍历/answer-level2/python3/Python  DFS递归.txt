用递归写的，方法和二叉树的层次遍历一样。 
用bfs和dfs迭代也都很简单，三种方法可见我那篇题解。


```
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        res=[]
        level=0
        def travel(root,level):
            if not root:
                return 
            if level>=len(res):
                res.append([])
            res[level].append(root.val)
            for i in root.children:
                travel(i,level+1)
        if not root: return []
        travel(root,level)
        return res
```


写个travel方法取叶子节点的值放到res数组里，用两个树分别跑这个方法，比较是否一样即可。
又写了个优化版，用的生成器，会一个个的生成节点并比较，在发现不等时可立即结束输出False，可以节省点内存

```
class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        res=[]
        def travel(root):
            if not root:
                return
            if not root.left and not root.right:
                res.append(root.val)
            travel(root.left)
            travel(root.right)
        travel(root1)
        res2=res
        res=[]
        travel(root2)
        return res==res2
```

优化版
```
class Solution: 
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        from itertools import zip_longest
        def travel(root):
            if not root:
                return 
            if not root.left and not root.right:
                yield root.val
            yield from travel(root.left)
            yield from travel(root.right)
        return all(a==b for a,b in zip_longest(travel(root1),travel(root2)))
    
```

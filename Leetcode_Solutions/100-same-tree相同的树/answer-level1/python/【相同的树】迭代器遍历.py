```
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        def print_treenode(treenode):
            if treenode:
                yield treenode.val
                for val in print_treenode(treenode.left):
                    yield val 
                for val in  print_treenode(treenode.right):
                    yield val 
            else:
                yield None
        pr = print_treenode(p)
        qr = print_treenode(q)
        for value in pr:
            if value != next(qr): return False
        return True
```
```py
class Solution:
    def twoSumBSTs(self, root1: TreeNode, root2: TreeNode, target: int) -> bool:

        r1 = self.inorder(root1)
        r2 = self.inorder(root2)

        i, j = 0, len(r2) - 1

        while i < len(r1) and j >= 0:
            if r1[i] + r2[j] == target:
                return True
            elif  r1[i] + r2[j] < target:
                i += 1
            elif r1[i] + r2[j] > target:
                j -= 1
        return False

    def inorder(self, root, res=None):
        if res is None:
            res = []

        if not root:
            return 

        self.inorder(root.left, res)
        res.append(root.val)
        self.inorder(root.right, res)

        return res
```


```py
class Solution:
    def twoSumBSTs(self, root1: TreeNode, root2: TreeNode, target: int) -> bool:

        iter1 = self.inorder_gen(root1)
        iter2 = self.inorder_gen(root2, reverse=True)

        i, j = next(iter1), next(iter2)

        while isinstance(i, int) and isinstance(j, int): 
            if i + j == target:
                return True
            elif i + j < target:
                i = next(iter1, None)
            elif i + j > target:
                j = next(iter2, None)
        return False

    def inorder_gen(self, node, reverse=False):
        if reverse:
            node_first = node.right
            node_last = node.left
        else:
            node_first = node.left
            node_last = node.right

        yield from self.inorder_gen(node_first, reverse) if node_first is not None else ()
        yield node.val
        yield from self.inorder_gen(node_last, reverse) if node_last is not None else ()
```

Reference: https://codereview.stackexchange.com/questions/183942/use-generator-to-do-inorder-traversal

However, using generator turns out to be slower (96ms 19.7M vs 184ms 16.8M)
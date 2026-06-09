```python
class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        # a node only has one parent
        # a tree must has and only has one root

        parent = [-1] * n
        for i in range(len(leftChild)):
            lchild, rchild = leftChild[i], rightChild[i]
            if lchild != -1:
                if parent[lchild] != -1: return False # more than one parent
                parent[lchild] = i
            if rchild != -1:
                if parent[rchild] != -1: return False
                parent[rchild] = i

        hasRoot = False
        for i in range(n):
            if parent[i] == -1:
                if not hasRoot: hasRoot = True
                else: return False # has two root
        return hasRoot
```
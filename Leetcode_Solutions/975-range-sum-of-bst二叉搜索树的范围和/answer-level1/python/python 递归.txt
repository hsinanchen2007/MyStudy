### 知识点：二叉搜索树的左儿子比自己小，右儿子比自己大。

### 解题思路：本题意在求二叉搜索树中所有满足节点值 L<val<R 的节点值之和。我们已知左儿子比自己小，所以当自己比L小时，不需要考虑左儿子，只需要考虑右儿子；同理，自己比R大时，只需要考虑左儿子；当自己在L和R之间时，左右儿子都要考虑，并且自己也要被加进去。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        def get_sum(node):
            if not node : return 0
            if node.val < L :
                return get_sum(node.right)
            if node.val >= L and node.val <= R:
                return get_sum(node.left) + get_sum(node.right) + node.val
            if node.val > R :
                return get_sum(node.left) 
        return get_sum(root)
        

```
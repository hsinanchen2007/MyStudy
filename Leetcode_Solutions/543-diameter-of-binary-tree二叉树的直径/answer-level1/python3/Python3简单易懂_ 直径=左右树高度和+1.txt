### 解题思路
递归计算树的高度
在递归过程中, 如果发现当前结点的左右子树和(就是直径)大于global_max就更新.

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# naive: 先找到所有结点的parent. 然后对每个结点做BFS, 得到最大距离. 这样子的开销O(N * (V + E))
# 但是这个太慢了一看就. 评论有大神提示说是每个结点的左右子树高度和 

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        def calc_tree_height(root):
            nonlocal global_max
            if root is None:
                return 0
            left_height = calc_tree_height(root.left)
            right_height = calc_tree_height(root.right)
            global_max = max(global_max, left_height + right_height)
            return 1 + max(left_height, right_height)
        global_max = 0
        calc_tree_height(root)
        return global_max
    
```
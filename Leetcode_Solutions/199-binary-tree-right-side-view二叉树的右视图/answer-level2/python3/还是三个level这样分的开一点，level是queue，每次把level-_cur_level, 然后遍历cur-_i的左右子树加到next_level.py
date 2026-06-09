### 解题思路
还是三个level这样分的开一点，level是queue，每次把level->cur_level, 然后遍历cur->i的左右子树加到next_level

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root is None:
            return None
        res = []
        level = [root]

        while level:
            cur_level = level
            next_level = []

            res.append(cur_level[-1].val)
            for idx, v in enumerate(cur_level):
                if v.left:
                    next_level.append(v.left)
                if v.right:
                    next_level.append(v.right)
            level = next_level

        return res




```
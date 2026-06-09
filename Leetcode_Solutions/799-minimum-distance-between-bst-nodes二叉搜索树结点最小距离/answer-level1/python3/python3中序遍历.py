### 解题思路
python3中序遍历

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        # 中序遍历
        if not root:
            return 0
        cur_stack = []
        cur_node = root
        min_diff = 300
        last_val = -100

        while cur_node or cur_stack:
            if cur_node:
                cur_stack.append(cur_node)
                cur_node = cur_node.left
            elif cur_stack:
                pop_item = cur_stack.pop()
                cur_diff = pop_item.val - last_val
                last_val = pop_item.val
                if cur_diff < min_diff:
                    min_diff = cur_diff

                cur_node = pop_item.right

        return min_diff





```
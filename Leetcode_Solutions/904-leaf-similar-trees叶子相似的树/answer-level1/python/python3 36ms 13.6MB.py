### 解题思路
1. 递归得到叶子列表，把左右子数的加起来，不加root的val，用字符串会出现bug，比如7，14和71，4分不出来
2. 比较叶子列表
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:

        def get_leaves(root):
            if not root:
                return []
            if not root.left and not root.right:
                return [root.val]
            else:
                return get_leaves(root.left) + get_leaves(root.right)
        list1 = get_leaves(root1)
        list2 = get_leaves(root2)
        return list1 == list2
```
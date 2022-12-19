### 解题思路
1. 利用二分查找查最后一层是否存在节点，前面都是满二叉树，节点为 2**d -1，加上最后一层的节点就可以算出所有的节点了
2. 递归
3. 利用递归来进行二分搜索，比第一种稍微简洁一些

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # def count_depth(self, root: TreeNode) -> int:
    #     d = 0
    #     while root.left:
    #        root = root.left
    #        d += 1
    #     return d

    # def exists(self, idx: int, d: int, node: TreeNode) -> bool:
    #     left, right = 0, 2**d - 1
    #     for _ in range(d):
    #         pivot = left + (right - left) // 2
    #         if idx <= pivot:
    #             node = node.left
    #             right = pivot
    #         else:
    #             node = node.right
    #             left = pivot + 1
    #     return node is not None

    # def countNodes(self, root: TreeNode) -> int:
    #     if not root:
    #         return 0
        
    #     d = self.count_depth(root)
    #     if d == 0:
    #         return 1
        
    #     left, right = 1, 2**d - 1
    #     while left <= right:
    #         pivot = left + (right - left) // 2
    #         if self.exists(pivot, d, root):
    #             left += 1
    #         else:
    #             right -= 1
    #     return 2**d-1 + left

    # def countNodes(self, root: TreeNode) -> int:
    #     return 1 + self.countNodes(root.left) + self.countNodes(root.right) if root else 0
    def countNodes(self, root: TreeNode) -> int:
        if root is None:
                return 0
        # step1: get h_left
        h_left = self.getLevel(root.left)
        # step2: get h_right
        h_right = self.getLevel(root.right)
        # step3: compare h_left and h_right
        if h_right == h_left: 
            return (1<<h_left) + self.countNodes(root.right)
        else:
            return self.countNodes(root.left) + (1<<(h_right))
    
    def getLevel(self, root):
        level = 0
        while root:
            root = root.left
            level += 1
        return level

```

```
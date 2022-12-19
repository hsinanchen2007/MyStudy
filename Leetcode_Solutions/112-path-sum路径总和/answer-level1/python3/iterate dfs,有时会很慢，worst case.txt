### 解题思路
1. 注意叶子节点的判断条件，
```
if not node.left and not node.right and curr_sum == 0:  
    return True
```
2. 非叶子节点需要向下递归or append 到stact里面

```
if node.right:
    de.append((node.right, curr_sum - node.right.val))
if node.left:
    de.append((node.left, curr_sum - node.left.val))
```
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# class Solution:
#     def hasPathSum(self, root: TreeNode, sum: int) -> bool:

        # def helper(node, target):
        #     if not node:
        #         return False
        #     if not node.right and not node.left:
        #         return node.val == target
        #     if target < 0:
        #         return False
            
        #     return helper(node.right, target-node.right.val) or helper(node.left, target-node.left.val)
        # if not root:
        #     return False
        # if not root.right and not root.left:
        #     return sum - root.val == 0
            
        # return self.hasPathSum(root.right, sum-root.val) or self.hasPathSum(root.left, sum-root.val)
        # return helper(root, sum)

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False
        de = [(root, sum - root.val), ]
        while de:
            node, curr_sum = de.pop()
            if not node.left and not node.right and curr_sum == 0:  
                return True
            if node.right:
                de.append((node.right, curr_sum - node.right.val))
            if node.left:
                de.append((node.left, curr_sum - node.left.val))
        return False

```
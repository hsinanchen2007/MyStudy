### 解题思路
两种方法效率差不多？

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
    # 方法1
    #     nums = []
    #     return self.method(root, nums)

    # def method(self, root: TreeNode, nums: List):
    #     if root is not None:
    #         if root.left:
    #             nums = self.method(root.left, nums)
    #         nums.append(root.val)
    #         if root.right:
    #             nums = self.method(root.right, nums)
    #         return nums


    # 方法2
        nums = []
        Y, N = 1, 0
        stack = [(N, root)]
        while stack:
            flag, cur = stack.pop()
            if cur is None: continue
            if flag == N:
                stack.append((N, cur.right))
                stack.append((Y, cur))
                stack.append((N, cur.left))
            else:
                nums.append(cur.val)
            
        return nums
```
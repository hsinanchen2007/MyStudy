### 解题思路
*这个内存消耗的指标有问题，leetcode的管理员和开发者多注意下吧，怎么样都是100%*

这个题目用递归实现比较简单，不过转换为迭代的话，难度会有所提升。
我在实现了递归后，翻了一下评论区和题解，略不满意，所以写了个迭代的实现方法，不快，图个乐。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        """迭代"""
        if not nums:
            return None

        stack = []
        
        node = None
        top_node = None
        stack.append(
            (0, len(nums), node)
        )
        while len(stack) > 0:
            left, right, node = stack.pop()

            mid = (left + right) >> 1
            if not node:
                node = TreeNode(nums[mid]) 
                top_node = node
            else:
                if nums[mid] < node.val:
                    node.left = TreeNode(nums[mid])
                    node = node.left
                else:
                    node.right = TreeNode(nums[mid])
                    node = node.right
            if left < mid:
                stack.append(
                    (left, mid, node)
                )
            if mid + 1 < right:
                stack.append(
                    (mid+1, right, node)
                )
        return top_node
            

    def sortedArrayToBST2(self, nums: List[int]) -> TreeNode:
        """递归"""
        if not nums:
            return None

        mid = len(nums) >> 1
        node = TreeNode(nums[mid])
        node.left = self.sortedArrayToBST(
            nums[:mid]
        )
        node.right = self.sortedArrayToBST(
            nums[mid+1:]
        )
        return node
```
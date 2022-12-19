### 解题思路
二叉搜索树, 如果用中序遍历, 生成的一定是一个升序列表.
那么我们就反其道而行之, 取中间元素为根节点, 取左半边为左子树, 右半边为右子树.

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
        def foo(nums, left, right):
            if left > right:
                return None
            mid = (left + right) // 2
            node = TreeNode(nums[mid])
            node.left = foo(nums, left, mid - 1)
            node.right = foo(nums, mid + 1, right)
            return node
        root = foo(nums, 0, len(nums) - 1)
        return root
            
```
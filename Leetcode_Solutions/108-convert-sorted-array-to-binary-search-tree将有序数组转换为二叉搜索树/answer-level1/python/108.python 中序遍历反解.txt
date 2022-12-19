### 解题思路
核心思想：寻找到数的中间节点，从中间节点触发,切分出左右子树列表，递归构造新的的左右子树

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
        # 将中序遍历反解,每次构造新的的左右子树
        if not nums:
            return None
        mid = len(nums)//2
        node = TreeNode(nums[mid])
        left = nums[:mid]
        right = nums[mid+1:]
        node.left = self.sortedArrayToBST(left)
        node.right = self.sortedArrayToBST(right)
        return node
```
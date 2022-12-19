### 解题思路
用索引不用数组复制应该会快一点吧。

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
        if not nums:
            return
        l,r=0,len(nums)-1
        def helper(l,r):
            if l>r:  return
            mid=(l+r+1)//2
            root=TreeNode(nums[mid])
            root.left=helper(l,mid-1)
            root.right=helper(mid+1,r)
            return root
        return helper(l,r)
        

            
```
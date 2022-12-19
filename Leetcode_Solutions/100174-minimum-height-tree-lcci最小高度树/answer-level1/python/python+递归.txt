### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if not nums:
            return 
        new_tree = TreeNode(nums[len(nums)//2])
        new_tree.left = self.sortedArrayToBST(nums[:len(nums)//2])
        new_tree.right = self.sortedArrayToBST(nums[len(nums)//2+1:])
        return new_tree
```
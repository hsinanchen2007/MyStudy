```
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        '''
        if nums is None: return None
        begin = 0
        end = len(nums)-1
        if begin>end:
            return None
        mid = (begin+end)>>1
        root = TreeNode(nums[mid])
        root.left = self.sortedArrayToBST(nums[begin:mid])
        root.right = self.sortedArrayToBST(nums[mid+1:end+1])
        return root
        '''
        if len(nums)==0: return
        mid_index = len(nums)//2
        root = TreeNode(nums[mid_index])
        root.left = self.sortedArrayToBST(nums[:mid_index])
        root.right = self.sortedArrayToBST(nums[mid_index+1:])
        return root
```

```
class Solution {
    func sortedArrayToBST(_ nums: [Int]) -> TreeNode? {
        return subArrayToBST(nums, left: 0, right: nums.count - 1)
    }
    
    func subArrayToBST(_ nums: [Int], left: Int, right: Int) -> TreeNode? {
        if right < left {
            return nil
        }
        let mid = (left + right) / 2
        let root = TreeNode(nums[mid])
        root.left = subArrayToBST(nums, left: left, right: mid - 1)
        root.right = subArrayToBST(nums, left: mid + 1, right: right)
        return root
    }
}
```
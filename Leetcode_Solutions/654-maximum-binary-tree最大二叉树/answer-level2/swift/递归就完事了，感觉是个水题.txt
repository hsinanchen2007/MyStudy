```
class Solution {
    func constructMaximumBinaryTreeHelper(_ nums: [Int], _ begin: Int, _ end: Int) -> TreeNode? {
        let len = nums.count
        if begin < 0 || end >= len || begin > end {
            return nil
        }
        if begin == end {
            return TreeNode(nums[begin])
        } else {
            //找到最大的那个
            var maxIdx = begin
            for i in stride(from: begin, through: end, by: 1) {
                if nums[i] > nums[maxIdx] {
                    maxIdx = i
                }
            }
            let root = TreeNode(nums[maxIdx])
            //分别再构造左子树和右子树
            root.left = constructMaximumBinaryTreeHelper(nums, begin, maxIdx - 1)
            root.right = constructMaximumBinaryTreeHelper(nums, maxIdx + 1, end)
            return root
        }
    }

    func constructMaximumBinaryTree(_ nums: [Int]) -> TreeNode? {
        let len = nums.count
        return constructMaximumBinaryTreeHelper(nums, 0, len - 1)
    }
}
```
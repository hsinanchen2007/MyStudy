class Solution {
    func sortedArrayToBST(_ nums: [Int]) -> TreeNode? {
        let count = nums.count
        if count == 0 {
            return nil
        }
        if count == 1 {
            return TreeNode.init(nums[0])
        }
        if count == 2 {
            let node = TreeNode.init(nums[0])
            node.left = nil
            node.right = TreeNode.init(nums[1])
            return node
        }
        if count == 3 {
            let node = TreeNode.init(nums[1])
            node.left = TreeNode.init(nums[0])
            node.right = TreeNode.init(nums[2])
            return node
        }
        let index = count / 2 + count % 2
        let c = nums[index-1]
        
        let node = TreeNode.init(c)
        let leftA = Array(nums[0...(index-2)])
        node.left = self.sortedArrayToBST(leftA)
        
        let rightA = Array(nums[(index)...(count-1)])
        node.right = self.sortedArrayToBST(rightA)
        

        return node
    }
}
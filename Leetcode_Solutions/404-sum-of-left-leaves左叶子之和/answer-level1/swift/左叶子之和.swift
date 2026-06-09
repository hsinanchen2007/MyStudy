
递归法

```swift []
class Solution {
    func sumOfLeftLeaves(_ root: TreeNode?) -> Int {
        guard let root = root else {
            return 0
        }
        
        var sum = 0
        
        if let left = root.left, left.left == nil, left.right == nil {
            sum = sum + left.val
        }
        
        return sum + sumOfLeftLeaves(root.left) + sumOfLeftLeaves(root.right)
    }
}
```
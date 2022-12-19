```swift []
class Solution {
    func maxDepth(_ root: TreeNode?) -> Int {
        if(root == nil) {
            return 0
        } else {
            var left = maxDepth(root!.left)
            var right = maxDepth(root!.right)
            return max(left, right) + 1
        }
    }
}
```

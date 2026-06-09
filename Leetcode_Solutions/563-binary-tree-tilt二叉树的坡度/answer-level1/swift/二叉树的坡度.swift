
递归法


```swift []
class Solution {
    func findTilt(_ root: TreeNode?) -> Int {
        guard let root = root else {
            return 0
        }
        
        var leftSum = 0
        preOrder(root.left) { (node) in
            leftSum = leftSum + node.val
        }
        
        var rightSum = 0
        preOrder(root.right) { (node) in
            rightSum = rightSum + node.val
        }
        
        let sum = abs(leftSum - rightSum)
        
        return sum + findTilt(root.left) + findTilt(root.right)
    }
    
    func preOrder(_ root: TreeNode?, _ excute: (TreeNode) -> Void) {
        guard let root = root else {
            return
        }
        
        excute(root)
        preOrder(root.left, excute)
        preOrder(root.right, excute)
    }
}
```

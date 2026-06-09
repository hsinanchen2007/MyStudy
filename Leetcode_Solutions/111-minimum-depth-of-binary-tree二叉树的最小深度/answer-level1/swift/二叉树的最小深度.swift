
递归法：

需要注意临界条件的判断，左右节点的空情况的枚举

```swift []
class Solution {
    func minDepth(_ root: TreeNode?) -> Int {
        
        guard let root = root else {
            return 0
        }
        
        if root.left == nil, root.right == nil {
            return 1
        }
        
        var minCount = Int.max
        
        if let left = root.left {
            minCount = min(minDepth(left), minCount)
        }
        
        if let right = root.right {
            minCount = min(minDepth(right), minCount)
        }
        
        return minCount + 1
        
    }
}
```


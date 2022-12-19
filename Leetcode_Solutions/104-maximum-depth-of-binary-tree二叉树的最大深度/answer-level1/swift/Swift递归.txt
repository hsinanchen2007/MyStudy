```
class Solution {
    func maxDepth(_ root: TreeNode?) -> Int {
        guard let root = root else{return 0}
        var current = 1
        var leftCount = 0
        var rightCount = 0
        if let left = root.left{
            leftCount = maxDepth(left)
        }
        if let right = root.right{
            rightCount = maxDepth(right)
        }
        if leftCount > rightCount{
            return current + leftCount
        }else{
            return current + rightCount
        }
    }
}
```
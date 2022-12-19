
递归法


```swift []
class Solution {
    func pathSum(_ root: TreeNode?, _ sum: Int) -> Int {
        
        guard let root = root else {
            return 0
        }
        
        return pathSum(root.left, sum) + pathSum(root.right, sum) + find(root, sum)
    }
    
    func find(_ root: TreeNode?, _ sum: Int) -> Int {
        
        guard let root = root else {
            return 0
        }
        
        var count = 0
        
        if root.val == sum {
            count = count + 1
        }
        
        return count + find(root.left, sum - root.val) + find(root.right, sum - root.val)
    }
}
```

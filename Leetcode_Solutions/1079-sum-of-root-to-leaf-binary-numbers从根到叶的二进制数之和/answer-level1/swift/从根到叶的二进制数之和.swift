
递归法：


```swift []
class Solution {
   func sumRootToLeaf(_ root: TreeNode?) -> Int {
        guard let root = root else {
            return 0
        }
        
        var sum = 0
        
        help(root, val: 0, sum: &sum)
        return sum
    }
    
    func help(_ root: TreeNode?, val: Int, sum: inout Int) {
        guard let root = root else {
            return
        }
        
        if root.left == nil, root.right == nil {
            let newVal = val<<1 | root.val
            sum = sum + newVal
            return
        }
        
        let newValue = val<<1 | root.val
        help(root.left, val: newValue, sum: &sum)
        help(root.right, val: newValue, sum: &sum)
    }
}
```

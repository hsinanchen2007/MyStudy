思路：先找出两棵树的所有叶子节点数组，再判断数组是否相同


```swift []
class Solution {
    func leafSimilar(_ root1: TreeNode?, _ root2: TreeNode?) -> Bool {
        guard let leave1 = findLeave(root1), let leave2 = findLeave(root2), leave1.count == leave2.count else {
            return false
        }
        
        for (i, v) in leave1.enumerated() {
            if leave2[i].val != v.val {
                return false
            }
        }
        return true
    }
    
    func findLeave(_ root: TreeNode?) -> [TreeNode]? {
        guard let root = root else {
            return nil
        }
        
        var result = [TreeNode].init()
        
        if let left = root.left, let leftLeave = findLeave(left) {
            result.append(contentsOf: leftLeave)
        }
        
        if let right = root.right, let rightLeave = findLeave(right) {
            result.append(contentsOf: rightLeave)
        }
        
        if root.left == nil, root.right == nil {
            result.append(contentsOf: [root])
        }
        
        return result
    }

}
```






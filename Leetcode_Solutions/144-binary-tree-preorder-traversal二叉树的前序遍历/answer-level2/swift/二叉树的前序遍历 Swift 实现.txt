
## 递归
```swift []
class Solution {
    func preorderTraversal(_ root: TreeNode?) -> [Int] {
        var res: [Int] = []
        guard let root = root else { return [] }
        res.append(root.val)
        res += preorderTraversal(root.left)
        res += preorderTraversal(root.right)
        return res
    }
}
```

## 迭代
```swift []
class Solution {
    func preorderTraversal(_ root: TreeNode?) -> [Int] {
        guard let root = root else { return [] }
        
        var res: [Int] = []
        var stack: [TreeNode] = [root]
        
        while let node = stack.popLast() {
            res.append(node.val)
            if let right = node.right { stack.append(right) }
            if let left = node.left { stack.append(left) }
        }
        
        return res
    }
}
```

## Morris算法

```swift []
class Solution {
    func preorderTraversal(_ root: TreeNode?) -> [Int] {
        var current: TreeNode? = root
        var res: [Int] = []
        
        while current != nil {
            res.append(current!.val)
            
            if let left = current!.left {
                // Find precursor.
                var prev = left
                while let right = prev.right, right !== current {
                    prev = right
                }
                
                if let right = current!.right, prev.right === right {
                    // Restore tree.
                    current = prev.right
                    prev.right = nil
                } else {
                    // Set thread.
                    prev.right = current!.right
                    current = left
                }
            } else {
                current = current!.right
            }
        }
        
        return res
    }
}
```
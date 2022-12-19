


```swift []
    // 递归法：
    func isBalanced(_ root: TreeNode?) -> Bool {
        
        guard let root = root else {
            return true
        }
        
        let left = height(root.left)
        let right = height(root.right)
        
        if abs(left - right) > 1 {
            return false
        }
        
        return isBalanced(root.left) && isBalanced(root.right)
    }

    // 迭代法
    func isBalanced(_ root: TreeNode?) -> Bool {
        guard let root = root else {
           return true
        }

        var queue: [TreeNode] = []
        queue.append(root)

        while !queue.isEmpty {
           let top = queue.removeFirst()

           let left = height(top.left)
           let right = height(top.right)

           if abs(left - right) > 1 {
               return false
           }

           if let left = top.left {
               queue.append(left)
           }

           if let right = top.right {
               queue.append(right)
           }
       }
       return true
    }
    
    
    func height(_ root: TreeNode?) -> Int {
        guard let root = root else {
            return 0
        }
        
        let sum = 1
        let leftHeight = height(root.left)
        let rightHeight = height(root.right)
        return sum + max(leftHeight, rightHeight)
    }

```

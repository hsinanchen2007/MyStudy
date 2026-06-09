
递归法：
中序遍历树是有序的，按照右中左遍历树是自减的，然后访问过的节点进行累加，可得出结果

```swift []

class Solution {
    func convertBST(_ root: TreeNode?) -> TreeNode? {
        var sum = 0
        inOrder2(root, &sum)
        return root
    }
    
    func inOrder2(_ root: TreeNode?, _ sum: inout Int) {
        guard let root = root else {
            return
        }
        
        if let right = root.right {
            inOrder2(right, &sum)
        }
        
        sum = sum + root.val
        root.val = sum
        
        if let left = root.left {
            inOrder2(left, &sum)
        }
    }
}

```

迭代法：
```swift []
func convertBST(_ root: TreeNode?) -> TreeNode? {
        guard let root = root else {
            return nil
        }
        
        var stack: [TreeNode] = [TreeNode]()
        
        var cur: TreeNode? = root
        var sum = 0
        while !stack.isEmpty || cur != nil {
            
            while cur != nil {
                stack.append(cur!)
                cur = cur?.right
            }
            
            if !stack.isEmpty {
                let top = stack.popLast()
                sum = sum + top!.val
                top?.val = sum
                cur = top?.left
                
            }
        }
        
        return root
    }
```
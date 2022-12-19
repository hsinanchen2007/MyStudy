
思路：

迭代法

```swift []
class Solution {
    func binaryTreePaths(_ root: TreeNode?) -> [String] {
        guard let root = root else {
            return []
        }
        
        var stack: [TreeNode] = []
        var path: [String] = []
        var result: [String] = []
        stack.append(root)
        let str = String(root.val) + "->"
        path.append(str)
        while let node = stack.popLast(), var p = path.popLast() {
            // 遍历node
            
            if let right = node.right {
                stack.append(right)
                path.append(p + String(right.val) + "->")
            }
            
            if let left = node.left {
                stack.append(left)
                path.append(p + String(left.val) + "->")
            }
            
            if node.left == nil, node.right == nil {
                p.removeSubrange(p.index(p.endIndex, offsetBy: -2)..<p.endIndex)
                // 叶子结点
                result.append(p)
            }
            
        }
        return result
    }
}
```

递归法：
```swift []
    func binaryTreePaths(_ root: TreeNode?) -> [String] {
        var result = [String].init()
        var str = ""
        searchPath(root, &result, str)
        return result
    }
    
    func searchPath(_ root: TreeNode?, _ result: inout [String], _ str: String) {
        guard let root = root else {
            return
        }
        
        if root.left == nil, root.right == nil {
            let path = str + String(root.val)
            result.append(path)
        }
        
        if let left = root.left {

            let newStr = str + String(root.val) + "->"
            searchPath(left, &result, newStr)
        }
        
        if let right = root.right {
            let newStr = str + String(root.val) + "->"
            searchPath(right, &result, newStr)
        }
    }
```
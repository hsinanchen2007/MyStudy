```
func isValidBST(_ root: TreeNode?) -> Bool {
        guard root != nil else {
            return true
        }
        var stack = [(root: TreeNode?, lower: Int, upper: Int)]()
        stack.append((root: root, lower: Int.min, upper: Int.max))
        while !stack.isEmpty {
            let element = stack.removeLast()
            if element.root == nil {
                continue
            }
            if element.lower >= element.root!.val || element.upper <= element.root!.val  {
                return false
            }
            stack.append((root: element.root!.left, lower: element.lower, upper: element.root!.val))
            stack.append((root: element.root!.right, lower: element.root!.val, upper: element.upper))
        }
        return true
    }
```
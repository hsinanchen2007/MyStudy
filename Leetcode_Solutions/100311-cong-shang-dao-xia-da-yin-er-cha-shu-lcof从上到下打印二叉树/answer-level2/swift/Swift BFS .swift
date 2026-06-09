```
class Solution {
    func levelOrder(_ root: TreeNode?) -> [Int] {
        guard root != nil else {
            return []
        }
        
        var queue = [TreeNode]()
        queue.append(root!)
        var res = [Int]()
        while !queue.isEmpty {
            let tmpNode = queue.removeFirst()
            res.append(tmpNode.val)
            if tmpNode.left != nil {
                queue.append(tmpNode.left!)
            }
            if tmpNode.right != nil {
                queue.append(tmpNode.right!)
            }
        }
        return res
    }
}
```
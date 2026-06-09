
递归法：
递归法求出所有节点的深度和父节点，存入map

```swift []
class Solution {
    func isCousins(_ root: TreeNode?, _ x: Int, _ y: Int) -> Bool {
        guard let root = root else {
            return false
        }
        
        var queue = [TreeNode]()
        queue.append(root)
        // key 子节点。value 父节点
        var parentMap: [Int : TreeNode] = [:]
        var depthMap: [Int : Int] = [:]
        var curDepth = -1

        while !queue.isEmpty {
            curDepth = curDepth + 1
            var next = [TreeNode]()
            for node in queue {
                depthMap[node.val] = curDepth

                if let left = node.left {
                    parentMap[left.val] = node
                    next.append(left)
                }

                if let right = node.right {
                    parentMap[right.val] = node
                    next.append(right)
                }

            }
            queue.removeAll()
            queue.append(contentsOf: next)
        }
        
        let xD = depthMap[x]
        let xP = parentMap[x]
        
        let yD = depthMap[y]
        let yP = parentMap[y]
        
        if let xD = xD, let yD = yD, xD == yD, let xP = xP, let yP = yP, xP.val != yP.val {
            return true
        }
        return false
    }
}
```

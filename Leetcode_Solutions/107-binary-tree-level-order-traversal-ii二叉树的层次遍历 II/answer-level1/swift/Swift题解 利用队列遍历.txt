利用队列遍历咯
Swift题解
```
class Solution {
    func levelOrderBottom(_ root: TreeNode?) -> [[Int]] {
        guard let r = root else {
            return [[Int]]()
        }
        var result = [[Int]]()
        var queue = [TreeNode]()
        queue.append(r)
        while queue.count > 0 {
            let layer = Array(queue)
            var layerVal = [Int]()
            queue.removeAll()
            for node in layer {
                layerVal.append(node.val)
                if let ln = node.left {
                    queue.append(ln)
                }
                if let rn = node.right {
                    queue.append(rn)
                }
            }
            result.insert(layerVal, at: 0)
        }
        return result
    }
}
```

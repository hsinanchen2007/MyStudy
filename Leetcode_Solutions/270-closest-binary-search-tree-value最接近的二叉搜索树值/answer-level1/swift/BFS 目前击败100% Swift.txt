直接BFS，一个队列遍历，一个队列用来存储target与每个节点的差值的绝对值，遍历完树之后再遍历差值的队列，找到最小的
```
class Solution {
    func closestValue(_ root: TreeNode?, _ target: Double) -> Int {
        guard let r = root else {
            return 0
        }
        var deltQueue = [(Int, Double)]()
        var queue = [TreeNode]()
        queue.append(r)
        var res = (r.val, abs(Double(r.val) - target))
        deltQueue.append((r.val, abs(Double(r.val) - target)))
        while queue.count > 0 {
            let tmp = Array(queue)
            queue.removeAll()
            for node in tmp {
                if let ln = node.left {
                    queue.append(ln)
                    deltQueue.append((ln.val, abs(Double(ln.val) - target)))
                }
                if let rn = node.right {
                    queue.append(rn)
                    deltQueue.append((rn.val, abs(Double(rn.val) - target)))
                }
            }
        }

        for delt in deltQueue {
            if delt.1 < res.1 {
                res = delt
            }
        }
        return res.0
    }
}
```
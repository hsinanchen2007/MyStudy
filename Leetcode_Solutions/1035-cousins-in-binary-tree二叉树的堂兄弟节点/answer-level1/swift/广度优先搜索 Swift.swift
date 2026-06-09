水题，直接bfs即可，
```
func isCousins(_ root: TreeNode?, _ x: Int, _ y: Int) -> Bool {
    guard let r = root else {
        return false
    }
    //dic[key]表示值为key的节点的父节点的值和深度
    var dic = [Int: (Int, Int)]()
    var queue = [TreeNode]()
    queue.append(r)
    var d = 0
    while queue.count > 0 {
        let tmp = Array(queue)
        queue.removeAll()
        d = d + 1
        for node in tmp {
            if let ln = node.left {
                queue.append(ln)
                dic[ln.val] = (node.val, d)
            }
            if let rn = node.right {
                queue.append(rn)
                dic[rn.val] = (node.val, d)
            }
        }
    }
    if let xi = dic[x] {
        if let yi = dic[y] {
            //父节点不相等但是深度相等 就返回true
            if xi.0 != yi.0 && xi.1 == yi.1 {
                return true
            }
        }
    }
    return false
}
```
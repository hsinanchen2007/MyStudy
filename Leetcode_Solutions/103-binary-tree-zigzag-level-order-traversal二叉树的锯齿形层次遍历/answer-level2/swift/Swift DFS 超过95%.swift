```
class Solution {
    var res = [[Int]]()
    func zigzagLevelOrder(_ root: TreeNode?) -> [[Int]] {
        guard root != nil else {
            return []
        }
        DFS(root, 0)
        return res
    }
    func DFS(_ root: TreeNode?, _ level: Int) -> Void {
        guard root != nil else {
            return
        }
        if res.count < level + 1 {
            res.append([])
        }
        if level & 1 == 1 {
            res[level].insert(root!.val, at: 0)
        } else {
            res[level].append(root!.val)
        }
        DFS(root?.left, level + 1)
        DFS(root?.right, level + 1)
    }
}
```
```
class Solution {
    func zigzagLevelOrder(_ root: TreeNode?) -> [[Int]] {
        var arr = [TreeNode]()
        var result = [[Int]]()
        guard let r = root else {
            return result
        }
        arr = [r]
        var level = 0
        while arr.count > 0 {
            var temp = [Int]()
            var newArr = [TreeNode]()
            for item in arr {
                temp.append(item.val)
                if let l = item.left {
                    newArr.append(l)
                }
                if let r = item.right {
                    newArr.append(r)
                }
            }
            result.append(level % 2 == 0 ? temp : temp.reversed())
            arr = newArr
            level += 1
        }
        return result
    }
}

```
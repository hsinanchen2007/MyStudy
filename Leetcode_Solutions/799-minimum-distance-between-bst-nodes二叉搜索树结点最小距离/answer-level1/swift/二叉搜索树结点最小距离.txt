
递归法：
中序遍历求出自增数组，对比数组相邻的数字

```swift []
class Solution {
    func minDiffInBST(_ root: TreeNode?) -> Int {
        guard let root = root else {
            return 0
        }
        
        var stack = [TreeNode].init()
        var cur: TreeNode? = root
        var valArray = [Int].init()
        var min = Int.max
        while !stack.isEmpty || cur != nil {
            while cur != nil {
                stack.append(cur!)
                cur = cur?.left
            }
            
            if !stack.isEmpty {
                let top = stack.popLast()
                valArray.append(top!.val)
                cur = top?.right
            }
        }
        
        for (i, v) in valArray.enumerated() {
            let nextIdx = i + 1
            if nextIdx < valArray.count, valArray[nextIdx] - v < min {
                min = valArray[nextIdx] - v
            }
        }
        return min
    }
}
```


迭代法：
中序遍历出自增的数组，然后对比相邻的两个数字，求出最小值

```swift []
class Solution {
    func getMinimumDifference(_ root: TreeNode?) -> Int {
        
        guard let root = root else {
            return -1
        }
        
        var stack: [TreeNode] = []
        var cur: TreeNode? = root
        var inOrderVal: [Int] = []
        while !stack.isEmpty || cur != nil {
            while let tmp = cur {
                stack.append(tmp)
                cur = cur?.left
            }
            
            if !stack.isEmpty, let top = stack.popLast() {
                inOrderVal.append(top.val)
                cur = top.right
            }
        }
        
        var min = Int.max
        for (i, v) in inOrderVal.enumerated() {
            if i + 1 < inOrderVal.count, inOrderVal[i+1] - v < min {
                min = inOrderVal[i+1] - v
            }
        }
        return min
    }
}
```


迭代法中序遍历，使用count（统计当前节点出现次数） maxCount(出现最大次数)   preVal(上一个众数) 去记录

```swift []
class Solution {
     func findMode(_ root: TreeNode?) -> [Int] {
        
        // 中序遍历
        guard let root = root else {
            return []
        }
        
        if root.left == nil, root.right == nil {
            return [root.val]
        }
        
        var stack: [TreeNode] = []
        var cur: TreeNode? = root
        var preVal: Int?
        var count = 0
        var maxCount = 0
        var result = [Int]()
        while !stack.isEmpty || cur != nil {
            while cur != nil {
                stack.append(cur!)
                cur = cur?.left
            }
            
            if !stack.isEmpty {
                let top = stack.popLast()
                if preVal == nil {
                    preVal = top?.val
                    count = 1
                } else if preVal == top!.val {
                    count = count + 1
                } else if preVal != top!.val {
                    if count == maxCount {
                        maxCount = count
                        result.append(preVal!)
                    } else if count > maxCount {
                        result.removeAll()
                        maxCount = count
                        result.append(preVal!)
                    }
                    preVal = top?.val
                    count = 1
                }
                cur = top?.right
            }
        }
        
        if count == maxCount {
            maxCount = count
            result.append(preVal!)
        } else if count > maxCount {
            result.removeAll()
            maxCount = count
            result.append(preVal!)
        }
        
        
        return result
    }
}
```

DFS 遍历树，记录每个节点的和以及出现最多数字的次数，再从字典中取出满足最多次数的值即可。

```swift
class Solution {
    private var sumMap: [Int: Int] = [: ]
    private var maxCount = 0
    
    func findFrequentTreeSum(_ root: TreeNode?) -> [Int] {
        _ = findSum(root)
        var ans: [Int] = []
        for (key, val) in sumMap where val == maxCount {
            ans.append(key)
        }
        return ans
    }
    
    func findSum(_ root: TreeNode?) -> Int {
        guard let root = root else {
            return 0
        }
        let leftSum = findSum(root.left)
        let rightSum = findSum(root.right)
        let sum = leftSum + rightSum + root.val
        let count = sumMap[sum, default: 0] + 1
        sumMap[sum] = count
        maxCount = max(maxCount, count)
        return sum
    }
}
```
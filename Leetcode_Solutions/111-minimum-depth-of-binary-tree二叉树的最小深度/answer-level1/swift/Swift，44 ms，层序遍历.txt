```swift
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */
class Solution {
    func minDepth(_ root: TreeNode?) -> Int {
        var todo: [TreeNode] = []
        guard let root = root else { return 0 }
        todo.append(root)
        var ans = 0
        while !todo.isEmpty {
            ans += 1
            var count = todo.count
            for index in 0..<count {
                let node = todo[index]
                if node.left == nil && node.right == nil {
                    return ans
                }
                if let left = node.left {
                    todo.append(left)
                }
                if let right = node.right {
                    todo.append(right)
                }
            }
            while count > 0 {
                count -= 1
                todo.removeFirst()
            }
        }
        return ans
    }
}
```
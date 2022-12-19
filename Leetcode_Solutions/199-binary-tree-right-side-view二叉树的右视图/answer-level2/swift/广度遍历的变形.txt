

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
func rightSideView(_ root: TreeNode?) -> [Int] {
    guard let tmp = root else { return [] }
    var queue = [tmp]
    var array = [Int]()
    while !queue.isEmpty {
        array.append(queue.last!.val)
        queue = queue.reduce([TreeNode]()) { $0 + [$1.left, $1.right].compactMap { $0 } }
    }
    return array
}
}
```
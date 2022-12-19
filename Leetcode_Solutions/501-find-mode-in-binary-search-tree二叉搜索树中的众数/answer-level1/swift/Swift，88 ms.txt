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
    var dict: [Int: Int] = [:]
    func findMode(_ root: TreeNode?) -> [Int] {
        nextNode(root)
        let sorted = Array(dict).sorted(by: { $0.value > $1.value })
        var ans = [Int]()
        for item in sorted {
            if item.value == sorted[0].value {
                ans.append(item.key)
            } else {
                break
            }
        }
        return ans
    }
    
    func nextNode(_ node: TreeNode?) {
        guard let node = node else { return }
        if dict.keys.contains(node.val) {
            dict[node.val]! += 1
        } else {
            dict.updateValue(1, forKey: node.val)
        }
        nextNode(node.left)
        nextNode(node.right)
    }
}
```
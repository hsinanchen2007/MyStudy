### 解题思路
此处撰写解题思路

### 代码

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
    public var paths: [[Int]] = []
    public var path: [Int] = []

    func pathSum(_ root: TreeNode?, _ sum: Int) -> [[Int]] {
        helper(root, sum)
        return paths
    }

    func helper(_ root: TreeNode?, _ sum: Int) {
        if root == nil {
            return
        }

        path.append(root!.val)
        var sumLeft = sum - root!.val

        if sumLeft == 0 && root?.left == nil && root?.right == nil {
            paths.append(Array(path))
        }
        if root?.left != nil {
            helper(root?.left, sumLeft)
        }
        if root?.right != nil {
            helper(root?.right, sumLeft)
        }

        path.removeLast()
    }
}
```
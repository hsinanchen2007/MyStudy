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
    func deleteNode(_ root: TreeNode?, _ key: Int) -> TreeNode? {
        // 1. find the node of key.
        var p = root
        var pp : TreeNode? = nil
        while p != nil && p?.val != key {
            pp = p
            p = p!.val > key ? p?.left : p?.right
        }
        if p == nil { return root } // not found 

        // 2. handle the node has two sub-nodes.
        if p?.left != nil && p?.right != nil {
            var minP = p?.right
            var minPP = p
            while minP?.left != nil {
                minPP = minP
                minP = minP?.left
            }
            p?.val = minP!.val
            pp = minPP
            p = minP
        }

        // 3. delete the node when only has one or zero sub-node.
        var child : TreeNode? = nil
        if p?.left != nil {
            child = p?.left
        } else if p?.right != nil {
            child = p?.right
        }

        if pp == nil { return child }   // delete the root node
        if pp?.left != nil && pp?.left?.val == p?.val {
            pp?.left = child
        } else if pp?.right != nil && pp?.right?.val == p?.val {
            pp?.right = child
        }
        return root
    }
}
```
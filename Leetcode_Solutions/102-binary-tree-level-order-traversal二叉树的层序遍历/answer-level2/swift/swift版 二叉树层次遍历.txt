深度优先
```
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
    var result = [[Int]]()

    func levelOrder(_ node: TreeNode?, level: Int) {
        if(result.count == level) {
            result.append([node!.val])
        }else {
            var tmp = result[level]
            tmp.append(node!.val)
            result[level] = tmp
        }
        if let left = node!.left {
            levelOrder(left, level: level + 1)
        }
        if let right = node!.right {
            levelOrder(right, level: level + 1)
        }
    }

    func levelOrder(_ root: TreeNode?) -> [[Int]] {
        if root != nil {
            levelOrder(root!, level: 0)
        }
        
        return result
    }
}
```
广度优先
```
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
    func levelOrder(_ root: TreeNode?) -> [[Int]] {
        if root == nil {
            return []
        }
        var result = [[Int]]()
        var nextLevel = [TreeNode]()
        var thisLevel: [TreeNode] = [root!]
        while thisLevel.count > 0 {
            var temp = [Int]()
            for node in thisLevel {
                temp.append(node.val)
                if let left = node.left {
                    nextLevel.append(left)
                }
                if let right = node.right {
                    nextLevel.append(right)
                }
            }
            result.append(temp)
            thisLevel = nextLevel
            temp.removeAll()
            nextLevel.removeAll()
        }
        return result
    }
}
```

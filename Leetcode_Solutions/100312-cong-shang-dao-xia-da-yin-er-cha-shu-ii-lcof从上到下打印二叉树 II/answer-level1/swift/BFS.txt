### 解题思路
1.二叉树的广度优先遍历
2.每次遍历，必去穷尽每一层
![WechatIMG1.jpeg](https://pic.leetcode-cn.com/31bbaf5dd5ba17866063440e2d8e42973b4086c2dd5f56e7f379f0e1787b4a84-WechatIMG1.jpeg)

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
 func levelOrder(_ root: TreeNode?) -> [[Int]] {
    if root == nil {
        return [[Int]]()
    }
    
    var result = [[Int]]()
    
    var queue = [TreeNode]()
    if let rootNode = root {
        queue.append(rootNode)
    }
    
    while !queue.isEmpty {
        let count = queue.count
        
        var temp:[Int] = [Int]()
        for i in stride(from: 0, to: count, by: 1) {
            let node = queue.removeFirst()
            temp.append(node.val)
            if let left = node.left {
                queue.append(left)
            }
            if let right = node.right {
                queue.append(right)
            }
        }
        result.append(temp)
    }
    
    return result
 }

}
```
### 解题思路
解题最开始想到的是方案一，但是会经历两次递归，求和与求坡度。
一开始题目的理解并不深刻，既然一棵**树的坡度就是左右子树节点和的差的绝对值**，那么在计算左右子树和的时候，把结果差值的绝对值记录下来即可。
即可减少一次递归，并且也不会有多大的空间损耗。
时间复杂度为O(n) ,空间复杂度O(n)。(n 表示节点数)

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
    // 方案一
    // func findTilt(_ root: TreeNode?) -> Int {
    //     guard let root = root else {
    //         return 0
    //     }
    //     return abs(calChildSum(root.left) - calChildSum(root.right)) + findTilt(root.left) + findTilt(root.right)  
    // }

    // func calChildSum(_ node: TreeNode?) -> Int {
    //     guard let node = node else {
    //         return 0
    //     }
    //     return node.val + calChildSum(node.left) + calChildSum(node.right)
    // }

    
    // 方案二
    func findTilt(_ root: TreeNode?) -> Int {
        var tilt = 0
        func calChildSum(_ node: TreeNode?) -> Int {
            guard let node = node else {
                return 0
            }
            let leftSum = calChildSum(node.left)
            let rightSum = calChildSum(node.right)
            tilt += abs(leftSum - rightSum)
            return node.val + leftSum + rightSum
        }
        calChildSum(root)
        return tilt
    }
    
}
```
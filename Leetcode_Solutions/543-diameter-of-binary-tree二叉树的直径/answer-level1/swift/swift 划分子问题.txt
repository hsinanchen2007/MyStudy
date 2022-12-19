### 解题思路

二叉树直径 = max(左子树直径,右子树直径,过根节点的直径)
过根节点的直径 = 左子树深度 + 右子树深度

一个节点的深度 = max(左子树深度,右子树深度)

求节点深度的同时可以记录一下当前最长直径, 初始化为0 

current = max(current,左子树+右子树深度)

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
    var currentDiameter = 0
    
    // 二叉树的直径 = max(左子树直径,右子树直径,过根节点的情况)
    // 过根节点时的直径 = 左子树深度 + 右子树深度
    // 一个节点的深度 = max(左子树深度, 右子树深度) + 1
    
    func diameterOfBinaryTree(_ root: TreeNode?) -> Int {
        let _ = deepth(root)
        return currentDiameter
    }
    
    // 求深度的同时可以记录当前直径最大值
    func deepth(_ root:TreeNode?) -> Int {
        guard let node = root else {
            return 0
        }
        
        let leftDeepth = deepth(node.left)
        let rightDeepth = deepth(node.right)
        
        currentDiameter = max(currentDiameter, leftDeepth+rightDeepth)
        return max(leftDeepth,rightDeepth) + 1
    }
}
```
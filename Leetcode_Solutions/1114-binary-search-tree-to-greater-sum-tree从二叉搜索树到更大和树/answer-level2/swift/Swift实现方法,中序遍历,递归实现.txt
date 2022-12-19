### 解题思路
使用中序遍历,但是先遍历右子树,然后根节点,再遍历左子树,因为是二叉搜索树,所以最大的在第一个,然后循环叠加赋值
使用的递归方法,可以改成迭代方法,加入stack,将节点入栈,时间复杂度会下降,当前时间复杂度O(n^2)

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

    var num = 0

    func bstToGst(_ root: TreeNode?) -> TreeNode? {
        if (root != nil) {
            if (root!.right != nil) {
                bstToGst(root!.right)
            }
            num += root!.val
            root!.val = num
            if (root!.left != nil) {
                bstToGst(root!.left)
            }
        }
        return root
    }
       
}
```
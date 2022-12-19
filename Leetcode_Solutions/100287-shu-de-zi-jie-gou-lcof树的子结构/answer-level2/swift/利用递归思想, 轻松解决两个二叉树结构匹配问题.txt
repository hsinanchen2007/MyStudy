### 解题思路
A树的每一个节点都可以是B树的根节点, 所以需要先遍历A树, 把每一个节点都尝试当作B树的根节点, 和B树比较
比较的过程可以看成是递归, 例如, A树的节点a, 和B树节点b相同, 则继续递归比较a,b节点和的左右节点

**有一点需要注意, 如果A树的某个节点有左右节点, 但是B树的对应节点没有左右节点, 这种情况下是不需要比较的, B树在本次递归中是符合要求的, 本次递归直接判断为true即可**

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
    func isSubStructure(_ A: TreeNode?, _ B: TreeNode?) -> Bool {
        // A树的每一个节点都可以是B树的根节点, 所以需要先遍历A树, 把每一个节点都尝试当作B树的根节点, 和B树比较
        // 比较的过程可以看成是递归, 例如, A树的节点a, 和B树根节点相同, 则继续递归比较a节点的左右节点
        
        // 这里直接用前序遍历, 中, 左, 右
        if A == nil || B == nil {
            return false
        }
        return _preOrder(A, B)
    }

    // 中, 左, 右
    func _preOrder(_ A: TreeNode?, _ B: TreeNode?) -> Bool {
        if A == nil {
            return false
        }

        if _isSameTree(A, B) {
            return true
        }else {
            return _preOrder(A!.left, B) || _preOrder(A!.right, B)
        }
    }

    func _isSameTree(_ A: TreeNode?, _ B: TreeNode?) -> Bool {
        if A == nil && B == nil {
            return true
        }
        // B节点是空的, A不为空, 说明不需要比较了, 直接返回true
        if B == nil {
            return true
        }
        
        if A == nil {
            // B不为空但是A已经是空的, 说明结构肯定不匹配, 返回false
            return false
        }
        
        if A?.val == B?.val {
            return _isSameTree(A!.left, B!.left) && _isSameTree(A!.right, B!.right)
        }else {
            return false
        }
    }
}
```
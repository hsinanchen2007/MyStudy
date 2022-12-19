```swift
class Solution {
    func isSubPath(_ head: ListNode?, _ root: TreeNode?) -> Bool {
        
        func check(_ treeNode: TreeNode?, _ currentListNode: ListNode?) -> Bool {
            guard let currentListNode = currentListNode else {
                return true
            }
            
            guard let treeNode = treeNode, treeNode.val == currentListNode.val else {
                return false
            }
            return check(treeNode.left, currentListNode.next) || check(treeNode.right, currentListNode.next)
        }
        
        func dfs(_ treeNode: TreeNode?) -> Bool {
            guard let treeNode = treeNode else {
                return false
            }
            if treeNode.val == head!.val {
                guard !check(treeNode, head) else {
                    return true
                }
            }
            guard !dfs(treeNode.left) else {
                return true
            }
            return dfs(treeNode.right)
        }
        return dfs(root)
    }
 }
```
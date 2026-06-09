
递归法：
最重要的是枚举出每一种情况不同的处理方式



```swift []
class Solution {

    func tree2str(_ t: TreeNode?) -> String {
        guard let root = t else {
            return ""
        }
        
        let left = tree2str(root.left)
        let right = tree2str(root.right)
        
        
        if root.left != nil, root.right != nil {
            return String(root.val) + "(\(left))" + "(\(right))"
        } else if root.left == nil, root.right != nil {
            return String(root.val) + "(\(left))" + "(\(right))"
        } else if root.left != nil, root.right == nil {
            return String(root.val) + "(\(left))"
        } else {
            return String(root.val)
        }

    }
}
```

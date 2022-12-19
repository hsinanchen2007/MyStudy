```
class Solution {
    var treeArray = [Int]()
    func kthLargest(_ root: TreeNode?, _ k: Int) -> Int {
        guard root != nil && k >= 1 else {
            return 0
        }
        self.inOrder(root)
        if k <= treeArray.count {
            return treeArray[treeArray.count - k]
        }
        return 0
    }
    func inOrder(_ root: TreeNode?) -> Void {
        guard root != nil else {
            return
        }
        inOrder(root?.left)
        treeArray.append(root!.val)
        inOrder(root?.right)
    }
}
```
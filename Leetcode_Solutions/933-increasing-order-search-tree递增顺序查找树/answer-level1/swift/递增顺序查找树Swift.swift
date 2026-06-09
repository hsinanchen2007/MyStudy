
递归法：

先递归中序遍历树（中序遍历就是一个自增的遍历），然后针对中序遍历的结果，重新构建树


```swift []
class Solution {
    
    func inOrder(_ root: TreeNode?, _ nodeArray: inout [Int]) {
        guard let root = root else {
            return
        }
        
        inOrder(root.left, &nodeArray)
        nodeArray.append(root.val)
        inOrder(root.right, &nodeArray)
    }
    
    func increasingBST(_ root: TreeNode?) -> TreeNode? {
        var nodeArray = [Int].init()
        inOrder(root, &nodeArray)
        var root: TreeNode? = nil
        var cur: TreeNode? = nil
        for val in nodeArray {
            let new = TreeNode.init(val)
            if root == nil {
                root = new
            } else {
                cur?.right = new
            }
            cur = new
        }
        return root
    }
}
```


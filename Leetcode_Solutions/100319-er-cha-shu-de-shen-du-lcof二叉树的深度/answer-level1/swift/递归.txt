##解题思路
就是简单的递归，只不过使用Swift时候需要注意解包
##代码如下
```
class Solution {
    func maxDepth(_ root: TreeNode?) -> Int {
        var thisNode : TreeNode
        if(root == nil){ return 0 }else{ thisNode = root! }
        var depth : Int = 0
        depth += 1 + max(maxDepth(thisNode.left), maxDepth(thisNode.right))
        return depth
    }
}
```

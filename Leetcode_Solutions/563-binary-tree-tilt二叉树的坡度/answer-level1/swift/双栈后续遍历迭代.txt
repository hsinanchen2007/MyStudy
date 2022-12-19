### 解题思路
就不递归！

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
    func findTilt(_ root: TreeNode?) -> Int {

        //初始化两个数组模拟stack，分别用来存放将要遍历的节点和已经探索完成的节点
        var stackDo = [root]
        var stackDone = [TreeNode?]()
        
        //后续遍历二叉树
        while !stackDo.isEmpty {
            
            let node = stackDo.removeLast()
            stackDone.append(node)
            
            if node?.left != nil {
                stackDo.append(node?.left)
            }
            
            if node?.right != nil {
                stackDo.append(node?.right)
            }

        }
        
        //初始化返回值
        var result = 0
        
        //修改二叉树，从底层往上，将每个节点的值加上它的子节点的值（如果子节点为空则加0），返回修改后每个节点的左子与右子的差的绝对值的和
        while !stackDone.isEmpty {

            if let node = stackDone.removeLast() {
                
                let leftSonVal = (node.left == nil ? 0 : node.left!.val)
                let rightSonVal = (node.right == nil ? 0 : node.right!.val)
                
                result += abs(leftSonVal - rightSonVal)
                node.val = node.val + leftSonVal + rightSonVal

            }
        }
        
        return result
    }
}
```
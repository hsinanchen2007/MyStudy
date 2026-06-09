### 解题思路
非递归用循环来遍历二叉树，因为树的单向性，所以需要一个栈来记录路径，方便处理完子节点后回到父节点。从栈中取数据出来有三中状态，需要不同的处理
状态1: 刚进入栈，还未处理左右节点；此时需要先处理左节点，左节点没有处理右节点
状态2: 左节点处理完成；此时需要处理右节点，右节点没有对自身进行处理
状态3: 右节点处理完成；此时需要对自身进行处理

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
    enum TreeNodeState {
        case initail
        case left
        case right
    }

    class TreeNodeWithState {
        var treeNode: TreeNode
        var state: TreeNodeState = .initail
        
        init(_ node: TreeNode) {
            treeNode = node
        }
    }

    func postorderTraversal(_ root: TreeNode?) -> [Int] {
        guard let root = root else {
            return []
        }
        var stack: [TreeNodeWithState] = [TreeNodeWithState(root)]
        var resultArr: [Int] = []
        
        while stack.count > 0 {
            let node = stack[stack.count-1]
            switch node.state {
            case .initail:
                if let left = node.treeNode.left {
                    node.state = .left
                    stack.append(TreeNodeWithState(left))
                } else if let right = node.treeNode.right {
                    node.state = .right
                    stack.append(TreeNodeWithState(right))
                } else {
                    _ = stack.popLast()
                    resultArr.append(node.treeNode.val)
                }
            case .left:
                if let right = node.treeNode.right {
                    node.state = .right
                    stack.append(TreeNodeWithState(right))
                } else {
                    _ = stack.popLast()
                    resultArr.append(node.treeNode.val)
                }
            case .right:
                _ = stack.popLast()
                resultArr.append(node.treeNode.val)
            }
        }

        return resultArr
    }
}
```
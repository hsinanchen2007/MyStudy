总体来说，二叉树的遍历就是将非线性的树结构，转化成线性结构。在遍历的过程中必然会遇到从子节点返回父节点的情况，所以我们需要使用某种数据结构暂存这些“历史记录”。

# 递归

递归算法实现起来简单易懂，可读性相当高。递归本质上使用了栈，只不过这个栈不需要我们进行维护，而是用于函数的递归调用。但是当二叉树过大的时候，递归算法可能会遇到调用栈过大而溢出的情况，不过“尾递归优化”可以缓解这一问题。

```swift []
class Solution {
    func inorderTraversal(_ root: TreeNode?) -> [Int] {
        guard let root = root else { return [] }
    
        var seq: [Int] = []
        seq += inorderTraversal(root.left)
        seq.append(root.val)
        seq += inorderTraversal(root.right)
        
        return seq
    }
}
```

# 迭代

迭代算法解决了递归算法的问题，但是稍微牺牲了一点可读性。可以这样理解：左侧的节点必定先于右侧的节点输出，所以对于任一子树，首先查找它最左侧的叶子节点，并且把这一路上经过的所有节点依次压入栈中。从栈中弹出一个节点输出它的值，再进入它的右孩子。重复上述步骤。

```swift []
class Solution {
    func inorderTraversal(_ root: TreeNode?) -> [Int] {
        var stack: [TreeNode] = []
        var result: [Int] = []
        var node: TreeNode? = root
        
        while node != nil || !stack.isEmpty {
            while node != nil {
                stack.append(node!)
                node = node!.left
            }
            
            node = stack.popLast()
            result.append(node!.val)
            node = node?.right
        }
        
        return result
    }
}
```

# Morris 算法
迭代算法的空间复杂度可以进一步优化。树的某些节点的`left`或`right`为空，我们可以利用这些空间来存储遍历过程中的前驱和后继，而不需要使用额外的栈。在 Morris 算法中，使用节点的`right`位置来储存它的后继，这样当我们访问完这个节点之后就可以进行通过`right`进入后继节点。（前驱和后继是以最终的输出序列为参照的）

对于一个节点，它的左子树的最右节点就是它的前驱节点。

为了确保总是有路可回，对于每一次迭代，在进行移动之前都先要查找当前节点的前驱节点，然后建立线索，使前驱节点的右孩子指向当前节点。

```swift []
class Solution {
    func inorderTraversal(_ root: TreeNode?) -> [Int] {
        var current, prev: TreeNode?
        var res: [Int] = []
        current = root
        
        while current != nil {
            if current!.left == nil {
                res += [current!.val]
                current = current!.right
            } else {
                prev = current!.left
                while prev!.right != nil && prev!.right !== current {
                    prev = prev!.right
                }
                
                if prev!.right === current {
                    prev!.right = nil
                    res += [current!.val]
                    current = current!.right
                } else {
                    prev!.right = current
                    current = current!.left
                }
            }
        }
        return res
    }
}
```
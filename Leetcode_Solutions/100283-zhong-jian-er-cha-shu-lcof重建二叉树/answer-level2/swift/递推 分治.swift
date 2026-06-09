``` swift

public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init(_ val: Int) {
        self.val = val
        self.left = nil
        self.right = nil
    }
}

class Solution {
    func buildTree(_ preorder: [Int], _ inorder: [Int]) -> TreeNode? {
        var p = preorder
        if p.isEmpty {
            return nil
        }
        let first = p.removeFirst()
        let firstIndex = inorder.firstIndex(of: first)!
        var leftI = [Int]()
        var rightI = [Int]()
        for i in stride(from: 0, to: inorder.count, by: 1) {
            if i == firstIndex {
                continue
            }
            if i < firstIndex {
                leftI.append(inorder[i])
            } else {
                rightI.append(inorder[i])
            }
        }
        let leftCount = leftI.count
        let node = TreeNode(first)
        var leftP = [Int]()
        var rightP = [Int]()
        for i in 0..<p.count {
            if i < leftCount {
                leftP.append(p[i])
            } else {
                rightP.append(p[i])
            }
        }
        
        node.left = buildTree(leftP, leftI)
        node.right = buildTree(rightP, rightI)
        return node
    }
}

let s = Solution()
s.buildTree([3,9,20,15,7], [9,3,15,20,7])

```

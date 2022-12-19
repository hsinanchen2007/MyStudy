### 解题思路
通过中序遍历，将树转换成两个有序的数组
合并两个有序数组

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
    func getAllElements(_ root1: TreeNode?, _ root2: TreeNode?) -> [Int] {
        /// 中序遍历两个树，得到两个有序数组，然后合并
        func midListFromTree(_ root: TreeNode?) -> [Int] {
            guard root != nil else {
                return []
            }
            /// 用数组模拟栈结构
            var nodeList = [TreeNode]()
            var result = [Int]()
            var pNode = root
            while pNode != nil || !nodeList.isEmpty {
                if let node = pNode {
                    nodeList.append(node)
                    pNode = node.left
                } else {
                    if let node = nodeList.last {
                        nodeList = nodeList.dropLast()
                        result.append(node.val)
                        pNode = node.right
                    }
                }
            }
            return result
        }
        
        let list1 = midListFromTree(root1)
        let list2 = midListFromTree(root2)
        var result = [Int]()
        var firstIndex = 0
        var secondIndex = 0
        while (firstIndex < list1.count && secondIndex < list2.count) {
            if list1[firstIndex] <= list2[secondIndex] {
                result.append(list1[firstIndex])
                firstIndex += 1
            } else {
                result.append(list2[secondIndex])
                secondIndex += 1
            }
        }
        
        if firstIndex < list1.count {
            result.append(contentsOf: list1.dropFirst(firstIndex))
        }
        
        if secondIndex < list2.count {
            result.append(contentsOf: list2.dropFirst(secondIndex))
        }
        
        return result
    }
}
```
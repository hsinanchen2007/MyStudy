1 使用层次遍历
2 针对计算各层的数据进行计算，从而规避了大数越界问题；使用下标而不是移除元素规避了在数组移除数据时时间复杂度太高的问题。 
`/**
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
    func widthOfBinaryTree(_ root: TreeNode?) -> Int {
                var result = 0
        if root != nil {
            var curLevelNodes:[TreeNode?] = []
            curLevelNodes.append(root)
            var leftIndex = 0
            var rightIndex = 0
            while true {
                leftIndex = -1
                rightIndex = -1
                for i in 0...curLevelNodes.count-1 {
                    if curLevelNodes[i] != nil {
                        leftIndex = i
                        break
                    }
                }
                for i in 0...curLevelNodes.count-1 {
                    if curLevelNodes[curLevelNodes.count-1-i] != nil {
                        rightIndex = curLevelNodes.count-1-i
                        break
                    }
                }

                if leftIndex == rightIndex && leftIndex == -1 {
                    break
                }
                
                var cur:[TreeNode?] = []
                result = max(result, rightIndex-leftIndex+1)
                for i in leftIndex...rightIndex {
                    let item = curLevelNodes[i]
                    cur.append(item?.left)
                    cur.append(item?.right)
                }
                curLevelNodes = cur
            }
        }
        return result
    }
}`
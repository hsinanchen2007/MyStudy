// ### 解题思路

// 先序遍历二叉树，将遍历到的节点值存放在一个set里，每次遍历到新值val，先看看set里是否存在一个值等于k-val

// ### 代码

// ```swift
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
    func findTarget(_ root: TreeNode?, _ k: Int) -> Bool {
        
        var node = root
        var stack = [TreeNode?]()//用数组模拟一个stack用来临时存放遍历到的节点
        var valueSet = Set<Int>()//初始化一个set用来存放遍历到的节点的值
        
        //先序遍历🌲
        while node != nil || !stack.isEmpty {
            
            if node != nil {
                
                //遍历到的新值先到set里找是否存在另外一个数使得两者相加等于k
                if valueSet.contains(k - node!.val) {
                    return true
                } else {
                    valueSet.insert(node!.val)
                }

                
                stack.append(node!)
                node = node?.left
            } else {
                
                node = stack.removeLast()
                node = node?.right
            }
        }
        
        return false
    }
}

// ```
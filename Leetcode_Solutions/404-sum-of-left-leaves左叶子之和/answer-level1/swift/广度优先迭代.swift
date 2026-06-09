### 解题思路
广度优先迭代

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
    func sumOfLeftLeaves(_ root: TreeNode?) -> Int {
        
        //初始化一个元素类型为元组的数组模拟stack
        var stack = [(root,0)]
        //定义返回值
        var result = 0
        
        
        //广度优先遍历🌲，只记录左子的值，当探索到叶时将左叶的值累加到返回值里
        while let node = stack.last?.0, let value = stack.last?.1 {

            stack.removeLast()
            
            if node.left != nil {
                stack.append((node.left!, node.left!.val))
            }
            
            if node.right != nil {
                stack.append((node.right!, 0))
            }
            
            if node.left == nil && node.right == nil {
                result += value
            }
        }
        
        return result
        
    }
}
```
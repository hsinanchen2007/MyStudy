### 解题思路
- 使用队列广度优先遍历
- 使用let if 进行解包
![剑指offer28.png](https://pic.leetcode-cn.com/72111007c62df3ada8b026ab45fc4191374a7a64374f51d1e5ffa85e52da51eb-%E5%89%91%E6%8C%87offer28.png)
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
    func mirrorTree(_ root: TreeNode?) -> TreeNode? {
        var queue = [TreeNode?]()
        queue.append(root)
        while queue.count > 0 {
            if let currentNode = queue.popLast(){
                if (currentNode != nil && (currentNode!.left != nil || currentNode!.right != nil)) {
                    let temp:TreeNode? = currentNode!.left
                    currentNode!.left = currentNode!.right
                    currentNode!.right = temp
                    queue.append(currentNode!.left)
                    queue.append(currentNode!.right)
                }
            }
        }
        return root
    }
}
```
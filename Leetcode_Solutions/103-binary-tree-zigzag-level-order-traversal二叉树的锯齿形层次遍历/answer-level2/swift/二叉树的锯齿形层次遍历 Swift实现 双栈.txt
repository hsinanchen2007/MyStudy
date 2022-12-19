这道题目的做法有很多，DFS和BFS都可以，既然题目属于`Stack`分类下，就是栈来实现。
主要思想是区分奇偶行，分别正序、逆序输出。这里用两个栈`odd`和`even`来分别表示奇数行和偶数行。交替处理这两个栈，也就是交替处理奇偶行。很显然，这里处理某个栈的意思就是循环`pop`并遍历栈中的所有节点：
- 如果是奇数行，则在循环`pop`的过程中，将下一行（偶数行）的节点从左至右压入偶数栈中。
- 如果是偶数行，则在循环`pop`的过程中，将下一行（奇数行）的节点从右至左压入奇数栈中。

```swift []
class Solution {
    func zigzagLevelOrder(_ root: TreeNode?) -> [[Int]] {
        guard let root = root else { return [] }
        var stacks = (
            odd: [TreeNode]([root]),
            even: [TreeNode]()
        )
        var res: [[Int]] = []
        
        while !stacks.odd.isEmpty || !stacks.even.isEmpty {
            var res1: [Int] = []
            while let node = stacks.odd.popLast() {
                if let left = node.left { stacks.even.append(left) }
                if let right = node.right { stacks.even.append(right) }
                res1.append(node.val)
            }
            
            var res2: [Int] = []
            while let node = stacks.even.popLast() {
                if let right = node.right { stacks.odd.append(right) }
                if let left = node.left { stacks.odd.append(left) }
                res2.append(node.val)
            }
            
            if !res1.isEmpty { res.append(res1) }
            if !res2.isEmpty { res.append(res2) }
        }
        
        return res
    }
}
```
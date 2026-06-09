```
class Solution {
    func listOfDepth(_ tree: TreeNode?) -> [ListNode?] {
        func __listOfDepth(_ root: TreeNode?, _ level: Int, _ result: inout [ListNode]) {
            guard let root = root else {
                return
            }
            if result.count == level {
                result.append(ListNode(root.val))
            } else {
                let node = ListNode(root.val)
                node.next = result[level]
                result[level] = node
            }
            // 注意这里是按从右到左的顺序去遍历每层，这样可以很方便的连接链表节点
            __listOfDepth(root.right, level + 1, &result)
            __listOfDepth(root.left, level + 1, &result)
        }
        var result: [ListNode] = []
        __listOfDepth(tree, 0, &result)
        return result
    }
}
```

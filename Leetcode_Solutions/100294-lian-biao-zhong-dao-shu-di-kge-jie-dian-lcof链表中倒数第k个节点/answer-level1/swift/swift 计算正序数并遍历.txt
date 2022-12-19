## 解题思路

首先计算出链表总节点数 `i`, `i-k` 则是目标节点的正向序号, 通过遍历的方式定位出目标节点, 导出即可

## 代码

```swift
class Solution {
    func getKthFromEnd(_ head: ListNode?, _ k: Int) -> ListNode? {
        guard head != nil else { return nil }

        var currentNode = head
        var resNode = head
        var i: Int = 0
        while currentNode != nil {
            currentNode = currentNode?.next
            i += 1
        }

        for _ in 0 ..< i - k {
            resNode = resNode?.next
        }

        return resNode
    }
}
```
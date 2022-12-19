### 解题思路
1. 用递归的方法求解，当l1 == null时返回l2，当l2 == null时返回l1。
2. 依次比较当前节点value的大小，取小
3. 将剩余的listnode进行递归构建

### 代码

```kotlin
/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    fun mergeTwoLists(l1: ListNode?, l2: ListNode?): ListNode? {
        if (l1 == null) {
            return l2
        }
        if (l2 == null) {
            return l1
        }
        var newListNode : ListNode? = null
        if (l1.`val` < l2.`val`) {
            newListNode = ListNode(l1.`val`)
            newListNode.next = mergeTwoLists(l2, l1.next)
        } else {
            newListNode = ListNode(l2.`val`)
            newListNode.next = mergeTwoLists(l1, l2.next)
        }
        return newListNode
    }
}
```
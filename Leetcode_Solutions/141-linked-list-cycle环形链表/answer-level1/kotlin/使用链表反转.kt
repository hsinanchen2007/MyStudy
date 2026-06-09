### 解题思路
`head = [3,2,0,-4], pos = 1` 链表反转的整个过程为：

`3->null, 2->3, 0->2, -4->0, 2->-4, 3->2`

但其实到 `2->-4` 就能判断出是一个循环链表，因为下一个是根节点，已经是重复了


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
    fun hasCycle(head: ListNode?): Boolean {
        var current = head
        var preNode: ListNode? = null
        var next: ListNode?
        while (current != null) {
            next = current.next
            if (next == head) {
                return true
            }

            current.next = preNode
            preNode = current
            current = next
        }
        return false
    }
}
```
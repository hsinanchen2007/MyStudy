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
    fun addTwoNumbers(l1: ListNode?, l2: ListNode?): ListNode? {
        if (l1 == null) return l2
        if (l2 == null) return l1
        var prev = ListNode(0)
        val dummy = prev
        var l1Clone = l1
        var l2Clone = l2
        var carry = 0
        var sum: Int
        while (l1Clone != null || l2Clone != null || carry > 0) {
            sum = (l1Clone?.`val` ?: 0) + (l2Clone?.`val` ?: 0) + carry
            carry = sum / 10

            val current = ListNode(sum % 10)
            prev.next = current
            prev = current

            l1Clone = l1Clone?.next
            l2Clone = l2Clone?.next
        }

        return dummy.next
    }
}
```

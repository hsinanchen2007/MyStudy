### 解题思路


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
    fun removeNthFromEnd(head: ListNode?, n: Int): ListNode? {
        var dummy = ListNode(0)
        dummy.next = head
        var target = dummy
        var find = dummy
        for(index in 1 .. n){
            find = find.next!!
        }
        while(find.next != null){
            find = find.next!!
            target = target.next!!
        }
        target.next = target.next!!.next
        return dummy.next
    }
}
```
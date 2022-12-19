### 解题思路
通过循环取出A链表的数字，再用这个值循环比较B链表的值找到合适的位置插入B链表中，最终B链表就会包含全部的数字。
注意：1、两个链表第一个数也要比较排序；2、链表插入时要生成新的ListNode，并重新连接链表。
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
        if (l1 == null || l2 == null)
            return l1 ?: l2
        else {
            val minFirstNode = if (l1.`val` <= l2.`val`) l1 else l2
            var temp: ListNode? = if (l1.`val` <= l2.`val`) l2 else l1
            while (temp != null) {
                var iteratorL11: ListNode = minFirstNode
                var iteratorL12: ListNode? = minFirstNode.next
                while (iteratorL12 != null && iteratorL12.`val` <= temp.`val`) {
                    iteratorL11 = iteratorL12
                    iteratorL12 = iteratorL12.next
                }
                iteratorL11.next = ListNode(temp.`val`)
                iteratorL11.next!!.next = iteratorL12
                temp = temp.next
            }
            return minFirstNode
        }
    }
}
```
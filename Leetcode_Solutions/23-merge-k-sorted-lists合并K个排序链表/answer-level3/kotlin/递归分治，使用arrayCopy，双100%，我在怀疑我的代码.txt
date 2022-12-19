```
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

    fun mergeKLists(lists: Array<ListNode?>): ListNode? {
        return when (lists.size) {
            0 -> null
            1 -> lists[0]
            2 -> mergeTwoSortedList(lists[0], lists[1])
            else -> {
                val splitSize = lists.size / 2
                val arr1 = arrayOfNulls<ListNode?>(splitSize)
                val arr2 = arrayOfNulls<ListNode?>(lists.size - splitSize)
                System.arraycopy(lists, 0, arr1, 0, splitSize)
                System.arraycopy(lists, splitSize, arr2, 0, arr2.size)
                mergeTwoSortedList(mergeKLists(arr1), mergeKLists(arr2))
            }
        }
    }

    fun mergeTwoSortedList(l1: ListNode?, l2: ListNode?): ListNode? {
        val result = ListNode(0)
        var rCurr = result
        var l1Curr = l1
        var l2Curr = l2
        while (l1Curr != null && l2Curr != null) {
            if (l1Curr.`val` < l2Curr.`val`) {
                rCurr.next = l1Curr
                rCurr = l1Curr
                l1Curr = l1Curr.next
            } else {
                rCurr.next = l2Curr
                rCurr = l2Curr
                l2Curr = l2Curr.next
            }
        }
        rCurr.next = l1Curr ?: l2Curr
        return result.next
    }

}
```
思路：
分治法将数组分成两半，判断数组size
    0：返回null
    1：返回lists[0]
    2：直接merge两个链表
    else：将数组拆成两半递归调用自身，并merge两个结果

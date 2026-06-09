### 解题思路
定义三个指针，lastLittleEndian指向小端的最后一个节点、current指向当前遍历到的节点、prevCurrent指向current的前置节点。

1. 当current.val>=x时，current和prevCurrent向前遍历；
2. 当current.val<x时，存在两种情况：
   21. lastLittleEndian.next==current时，把lastLittleEndian指针前移，继续遍历；
   22. lastLittleEndian.next!=current时，把current移到lastLittleEndian之后，然后重置相关指针，继续遍历。

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode dummy = new ListNode(Integer.MIN_VALUE);
        dummy.next = head;

        ListNode lastLittleEndian = dummy, prevCurrent = lastLittleEndian, current = head;
        while (current != null) {
            if (current.val < x) {
                if (lastLittleEndian.next != current) {
                    prevCurrent.next = current.next;
                    current.next = lastLittleEndian.next;
                    lastLittleEndian.next = current;

                    lastLittleEndian = current;
                    current = prevCurrent.next;
                } else {
                    lastLittleEndian = current;
                    prevCurrent = current;
                    current = current.next;
                }
            } else {
                prevCurrent = current;
                current = current.next;
            }
        }

        return dummy.next;
    }
}
```
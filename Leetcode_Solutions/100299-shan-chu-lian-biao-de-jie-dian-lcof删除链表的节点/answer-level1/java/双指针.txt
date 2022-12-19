```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode fir = dummy;
        ListNode sec = dummy;
        fir = fir.next;
        while(fir.val != val) {
            fir = fir.next;
            sec = sec.next;
        }
        sec.next = sec.next.next;
        return dummy.next;
    }
}
```
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        fir = dummy
        sec = dummy
        fir = fir.next
        while fir.val != val:
            fir = fir.next
            sec = sec.next
        sec.next = sec.next.next
        return dummy.next
```

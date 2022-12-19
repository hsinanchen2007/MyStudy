```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def kthToLast(self, head: ListNode, k: int) -> int:
        dummy = ListNode(0)
        dummy.next = head
        fir = dummy
        sec = dummy
        for i in range(k + 1):
            fir = fir.next
        while fir:
            fir = fir.next
            sec = sec.next
        return sec.next.val
```
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
    public int kthToLast(ListNode head, int k) {
        ListNode dummy = new ListNode(0);//与删除倒数第n个结点类似，双指针
        dummy.next = head;
        ListNode fir = dummy;
        ListNode sec = dummy;
        for(int i = 0; i <= k; i++) {//相差n+1个
            fir = fir.next;
        }
        while(fir != null) {
            fir = fir.next;
            sec = sec.next;
        }
        return sec.next.val;
    }
}
```

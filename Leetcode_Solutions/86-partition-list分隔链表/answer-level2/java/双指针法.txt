如图
```
class Solution {
    public ListNode partition(ListNode head, int x) {

        ListNode newhead = new ListNode(0);
        newhead.next = head;
        ListNode fast = newhead, slow = newhead;

        while (fast.next != null) {
            if (slow.next.val >= x) {
                if (fast.next.val < x) {
                    ListNode temp = slow.next;
                    slow.next = fast.next;
                    fast.next = fast.next.next;
                    slow.next.next = temp;
                    slow = slow.next;
                } else {
                    fast = fast.next;
                }
            } else {
                slow = slow.next;
                fast = fast.next;
            }
        }

        return newhead.next;
    }
}
```

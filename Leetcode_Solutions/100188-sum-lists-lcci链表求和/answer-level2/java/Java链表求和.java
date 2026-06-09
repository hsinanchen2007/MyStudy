```
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if ( l1 == null || l2 == null ) {
            return (l1 == null) ? l2 : l1;
        }

        int isCarry = 0;
        ListNode head = new ListNode(0);
        ListNode cur = head;
        int sum = 0;
        while( l1 != null && l2 != null ) {
            sum  = l1.val + l2.val + isCarry;
            cur.next = new ListNode(sum % 10);
            isCarry = (sum >= 10) ? 1 : 0;
            cur = cur.next;
            l1 = l1.next;
            l2 = l2.next;
        }
        while( l1 != null ) {
            sum = l1.val + isCarry;
            cur.next = new ListNode(sum % 10);
            isCarry = (sum >= 10) ? 1 : 0;
            cur = cur.next;
            l1 = l1.next;
        }
        while( l2 != null ) {
            sum = l2.val + isCarry;
            cur.next = new ListNode(sum % 10);
            isCarry = (sum >= 10) ? 1 : 0;
            cur = cur.next;
            l2 = l2.next;
        }
        if ( isCarry == 1 ) {
            cur.next = new ListNode(1);
        }
        return head.next;
    }
}
```

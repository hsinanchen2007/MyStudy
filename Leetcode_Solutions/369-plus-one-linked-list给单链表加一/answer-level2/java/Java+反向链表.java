和445.两数相加2 类似。
先反向链表，末尾加1，然后再反向回来。要注意进位。
```
class Solution {
    public ListNode plusOne(ListNode head) {
        ListNode rev = reverse(head);
        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;
        int step = 1;
        while (rev != null) {
            int num = rev.val + step;
            step = num / 10;
            cur.next = new ListNode(num % 10);
            cur = cur.next;
            rev = rev.next;
        }
        if (step == 1) {
            cur.next = new ListNode(step);
        }
        return reverse(dummy.next);
    }

    private ListNode reverse(ListNode head) {
        ListNode prev = null;
        ListNode cur = head;
        while (cur != null) {
            ListNode tmp = cur.next;
            cur.next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
}
```

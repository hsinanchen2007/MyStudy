个人思路是遍历给定链表，奇数位置放在一个链表中，偶数位置放在一个链表中，然后奇数链表和偶数链表连接起来返回即可。

public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode dummy1 = new ListNode(0);
        ListNode dummy2 = new ListNode(0);
        ListNode cur1 = dummy1;
        ListNode cur2 = dummy2;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        int i = 1;
        while (dummy != null) {
            if (i % 2 == 1) {
                cur1.next = dummy.next;
                cur1 = cur1.next == null ? cur1 : cur1.next;
            } else {
                cur2.next = dummy.next;
                cur2 = cur2.next == null ? cur2 : cur2.next;
            }
            dummy = dummy.next;
            i++;
        }
        cur1.next = dummy2.next;
        return dummy1.next;
    }
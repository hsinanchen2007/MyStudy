思路：将奇节点放在一个链表里，偶链表放在另一个链表里。然后将奇数链表的尾指针指向偶数链表的头指针
更多链表的问题参考[此文](https://blog.csdn.net/reed1991/article/details/98884225)
```
public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null) {
            return head;
        }
        ListNode odd = new ListNode(-1);
        ListNode oddHead = odd;
        ListNode even = new ListNode(-1);
        ListNode evenHead = even;
        while (head != null && head.next != null) {
            odd.next = head;
            even.next = head.next;
            odd = odd.next;
            even = even.next;
            head = head.next.next;
        }
        //防止最后还有一个节点
        if (head != null) {
            odd.next = head;
            odd = odd.next;
            even.next = null;
        }
        odd.next = evenHead.next;
        return oddHead.next;

    }
```

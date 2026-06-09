 /*
     *奇链表的头结点是head，尾节点是odd，奇节点下一个节点是偶节点的下一个节点
     *偶链表的头结点是head.next需要用一个变量evenHead保存，尾节点是even，偶节点下一个节点是偶节点的下一个节点
    **/
```
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null) {
            return head;
        }
        ListNode odd = head;
        ListNode even = head.next;;
        ListNode evenHead = even;//保存偶链表头节点
        while (odd.next != null && even.next != null) {;
            odd.next = even.next;
            odd = odd.next;
            even.next = odd.next;
            even = even.next;
        }
        odd.next = evenHead;
        return head;
    }
```
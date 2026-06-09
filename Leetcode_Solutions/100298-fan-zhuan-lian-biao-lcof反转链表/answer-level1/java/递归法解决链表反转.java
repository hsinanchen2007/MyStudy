思路：
    通过递归使得除原链表的head所指节点外的所有结点依次成为ListNode newHead，最后改变原链表head所指节点的指向。注意要判断传进的head和head.next是否为空.
```
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        ListNode newHead = reverseList(head.next);

        head.next.next = head;
        head.next = null;
        return newHead;
    }
```


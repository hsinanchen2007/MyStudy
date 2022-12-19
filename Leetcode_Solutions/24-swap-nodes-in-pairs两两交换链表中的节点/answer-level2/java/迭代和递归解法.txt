两两交换，迭代交换上主要需要注意一点需要保存已交换链表的尾节点，比如说 
1->2->3->4->5->6
单链表只能向下遍历，1->2 交换成2->1 之后需要保存节点1，以便构造后面的 1->4->3

迭代解决：

```
public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode dumpy = new ListNode(-1);
        ListNode node1 = head, node2 = head.next, pre = null;
        dumpy.next = node2;
        while (true) {
            node1.next = node2.next;
            node2.next = node1;
            if (pre != null) pre.next = node2;
            pre = node1;
            if (node1.next == null) return dumpy.next;
            node1 = node1.next;
            if (node1.next == null) return dumpy.next;
            node2 = node1.next;
        }
    }
```

递归解法:
```
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode swaps = swapPairs1(head.next.next);
        ListNode next = head.next;
        head.next = swaps;
        next.next = head;
        return next;
    }
```

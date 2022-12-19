```
 public ListNode removeElements(ListNode head, int val) {
        if (head == null) return head;
        ListNode sentinel = new ListNode(-1000);
        sentinel.next = head;
        ListNode pre = sentinel;
        while (head != null) {
            if (head.val == val) {
                pre.next = head.next; // 删除当前节点，前驱节点不变
            } else {
                pre = head; // 假如不删除当前节点，走正常遍历，那么前驱节点需要后移
            }
            head = head.next;
        }
        return sentinel.next;
    }
```

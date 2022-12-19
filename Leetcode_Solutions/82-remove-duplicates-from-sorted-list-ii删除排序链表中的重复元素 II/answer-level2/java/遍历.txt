# 遍历链表
**遍历链表，将当前节点的上个节点的值保存在temp中，每次遍历的时候比较当前值与temp、下一节点的值是否相同，若不相同就将当前节点添加进来。**
```
public ListNode deleteDuplicates(ListNode head) {
        ListNode result = new ListNode(0);
        ListNode curr = result;
        int temp = -100;
        while (head != null) {
            ListNode next = head.next;
            if ((next == null && temp != head.val) || (next != null && temp != head.val && next.val != head.val)) {
                ListNode node = new ListNode(head.val);
                curr.next = node;
                curr = curr.next;
            }
            temp = head.val;
            head = head.next;
        }
        return result.next;
    }
```


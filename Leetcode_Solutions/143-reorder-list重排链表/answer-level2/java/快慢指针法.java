**通过快慢指针把链表分成前后两个部分，然后把后半部分的节点反转后依次插入到前半部分当中即可**
```
public void reorderList(ListNode head) {
        if (head == null || head.next == null) return;
        ListNode fast = head;
        ListNode slow = head;
        while (fast.next != null && fast.next.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        ListNode end = reverse(slow.next);
        slow.next = null;
        ListNode curr = head;
        while (end != null) {
            ListNode node = new ListNode(end.val);
            node.next = curr.next;
            curr.next = node;
            curr = curr.next.next;
            end = end.next;
        }
    }

    /**     反转链表    */
    private ListNode reverse(ListNode head) {
        ListNode h = head;
        ListNode prev = null;
        while (h != null) {
            ListNode node = new ListNode(h.val);
            node.next = prev;
            prev = node;
            h = h.next;
        }
        return prev;
    }
```

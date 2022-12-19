```
 public static ListNode removeDuplicateNodes(ListNode head) {
        if (head == null) {
            return head;
        }

        Set<Integer> set = new HashSet<>();
        set.add(head.val);

        ListNode current = head;
        while (current.next != null) {
            ListNode next = current.next;

            if (set.contains(next.val)) {
                current.next = next.next;
            } else {
                current = current.next;
                set.add(current.val);
            }
        }

        return head;
    }
```

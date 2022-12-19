```
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (head == null || head.next == null) return head;
        LinkedList<ListNode> deque = new LinkedList<>();
        ListNode p = head;
        while (p != null) {
            deque.add(p);
            p = p.next;
        }
        m -= 1;
        n -= 1;
        while (m < n) {
            ListNode front = deque.get(m++);
            ListNode behind = deque.get(n--);
            int temp = front.val;
            front.val = behind.val;
            behind.val = temp;
        }
        return head;
    }
```

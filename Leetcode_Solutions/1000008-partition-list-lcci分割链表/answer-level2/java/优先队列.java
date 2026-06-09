# 代码
```java
class Solution {
    public ListNode partition(ListNode head, int x) {
        if (head == null) return null;
        PriorityQueue<ListNode> queue = new PriorityQueue<>((l, r) -> l.val - r.val);
        while (head != null) {
            queue.offer(head);
            head = head.next;
        }
        head = queue.poll();
        ListNode res = head;
        while (!queue.isEmpty() && head.val < x)
            head.next = (head = queue.poll());
        for (ListNode node : queue) {
            head.next = node;
            head = node;
        }
        head.next = null;
        return res;
    }
}
```

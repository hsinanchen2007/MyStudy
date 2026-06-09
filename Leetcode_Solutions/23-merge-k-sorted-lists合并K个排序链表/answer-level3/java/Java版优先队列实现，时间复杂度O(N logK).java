```
public ListNode mergeKLists(ListNode[] lists) {
    PriorityQueue<ListNode> queue = new PriorityQueue<>(Comparator.comparingInt(node -> node.val));
    ListNode dummy = new ListNode(0);
    ListNode p = dummy;
    queue.addAll(Stream.of(lists).filter(Objects::nonNull).collect(Collectors.toList()));
    while (!queue.isEmpty()) {
        ListNode node = queue.poll();
        p.next = node;
        p = p.next;
        if (node.next != null)
            queue.add(node.next);
    }
    return dummy.next;
}
```

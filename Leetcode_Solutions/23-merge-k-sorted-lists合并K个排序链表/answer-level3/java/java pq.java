### 解题思路
很简单的调包。我调包我开心。

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
        public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<Integer> minpq = new PriorityQueue<>();
        Arrays.stream(lists).flatMap(this::getStream).forEach(minpq::offer);
        if (minpq.size() == 0) {
            return null;
        }
        ListNode listNode = new ListNode(minpq.poll());
        ListNode cmp = listNode;
        while (minpq.size() != 0) {
            Integer integer = minpq.poll();
            cmp.next = new ListNode(integer);
            cmp = cmp.next;
        }
        return listNode;
    }

    private Stream<Integer> getStream(ListNode cmp) {
        List<Integer> list = new ArrayList<>();
        while (cmp != null) {
            list.add(cmp.val);
            cmp = cmp.next;
        }
        return list.stream();
    }
}
```
首先将所有链表的首元素加入优先队列，再从小到大依次取出元素，取出后放入下一个元素。

注释掉的写法为Java 8特性，写着虽然比较方便，但运行会慢一些。
```java
import java.util.*;

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        PriorityQueue<ListNode> queue = new PriorityQueue<>(Comparator.comparingInt(o -> o.val));
        //Arrays.stream(lists).filter(Objects::nonNull).forEach(queue::add);
        for (ListNode node : lists) {
            if (node != null) {
                queue.add(node);
            }
        }

        ListNode head = new ListNode(0);
        ListNode ptr = head;

        while (!queue.isEmpty()) {
            ListNode node = queue.poll();
            ptr.next = node;
            ptr = ptr.next;
            //Optional.ofNullable(node.next).ifPresent(queue::add);
            if (node.next != null) {
                queue.add(node.next);
            }
        }

        return head.next;
    }
}
```
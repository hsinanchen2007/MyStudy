### 解题思路
小顶堆

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
        if(lists == null) {
            return null;
        }

        Queue<ListNode> queue = new PriorityQueue<>(Comparator.comparingInt(o -> o.val));
        for (int i = 0; i < lists.length; i++) {
            if(lists[i] != null) {
                queue.add(lists[i]);
            }
        }

        ListNode dummy = new ListNode(-1);
        ListNode node = dummy;
        while(!queue.isEmpty()) {
            ListNode poll = queue.poll();
            node.next = poll;
            node = node.next;
            if(poll.next != null) {
                queue.add(poll.next);
            }
        }

        return dummy.next;
    }
}
```
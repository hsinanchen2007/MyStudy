### 解题思路
K里面找最小的，最好的办法就是维护一个小顶堆，效率不错，整体效率为NlogK。

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
        int k = lists.length;
        PriorityQueue<ListNode> priorityQueue = new PriorityQueue<>(new Comparator<ListNode>() {
            @Override
            public int compare(ListNode o1, ListNode o2) {
                return o1.val - o2.val;
            }
        });

        ListNode dummy = new ListNode(-1);
        ListNode res = dummy;

        for (int i = 0; i < k; i++) {
            if (lists[i] != null) {
                priorityQueue.add(lists[i]);
            }
        }
        while (!priorityQueue.isEmpty()) {
            ListNode cur = priorityQueue.poll();
            dummy.next = cur;
            dummy = dummy.next;
            if (cur.next != null) {
                priorityQueue.add(cur.next);
            }
        }
        return res.next;
    }
}
```
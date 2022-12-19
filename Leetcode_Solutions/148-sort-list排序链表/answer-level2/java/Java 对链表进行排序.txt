### 解题思路
最简单的就是借助于优先队列，实现小顶堆！！！
依次输入优先队列，然后依次输出优先队列即可。
这种解法击败的用户比较少，看来时间和空间有很大提升空间。
但是确实是一种思路，记录下来。

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
    public ListNode sortList(ListNode head) {
		PriorityQueue<ListNode> queue = new PriorityQueue(new Comparator<ListNode>() {
			public int compare(ListNode o1, ListNode o2) {
				return (o1.val - o2.val);
			}
		}); // 小顶堆
        
        while (head != null) {
            queue.offer(head);
            head = head.next;
        }
        
        ListNode newHead = new ListNode(0);
        ListNode p = newHead;
        while (!queue.isEmpty()) {
            p = p.next = queue.poll();
        }
        p.next = null;
        return newHead.next;
    }
}
```
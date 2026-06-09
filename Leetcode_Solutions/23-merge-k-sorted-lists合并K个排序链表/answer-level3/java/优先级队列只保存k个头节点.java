### 解题思路

使用优先级队列:
- 队列中最多只有k个元素(可能小于k), 建立一个大小为k的小顶堆的复杂度为O(k)
- 对于每个元素, 出堆后堆的调整的复杂度为O(log k), 因此n个元素出堆入队的复杂度为 O(n * log k)
- 总的复杂度为O(n*log(k))

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
        PriorityQueue<ListNode> heap = new PriorityQueue<>((o1, o2) -> o1.val - o2.val);
        // 优先级队列堆, 保证堆中只有最多k个元素
        for(ListNode head: lists){
            if(head != null){
                heap.offer(head);
            }
        }
        ListNode dummy = new ListNode(-1);
        ListNode cur = dummy;
        // 当去除一个元素时, 对应的元素的后驱如果不为空可以入队
        while(!heap.isEmpty()){
            // 最小节点出队
            ListNode node = heap.poll();
            // 当前节点的后驱设置为该节点
            cur.next = node;
            // 该节点变为当前节点
            cur = node;
            if(cur.next != null){ // 当前节点的后驱不为空, 则入队
                heap.offer(cur.next);
            }
        }
        return dummy.next;
    }
}
```
### 解题思路
利用优先队列，把链表元素放进去，理由底层排序原理，对其大顶堆排序，在把排序好的节点拿出来连接成链表

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
        ListNode dummynode = new ListNode(-1);
        ListNode dummy  = dummynode;
        PriorityQueue<ListNode> pq = new PriorityQueue<>(new Comparator<ListNode>(){
            @Override
            public int compare(ListNode o1,ListNode o2) {
                return o1.val - o2.val;
            }
        });
        while(head !=null) {
            pq.add(head);
            head = head.next;
        }
        while(!pq.isEmpty()) {
            dummy.next =pq.poll();
            dummy = dummy.next;
        }
        //这里需要最后一个指针指向空，不然超时
        dummy.next = null;
        return dummynode.next;
    }
}
```
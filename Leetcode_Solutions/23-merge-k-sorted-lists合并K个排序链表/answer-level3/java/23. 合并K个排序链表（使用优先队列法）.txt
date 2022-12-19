### 解题思路
使用优先队列，先把每个链表的头节点放入优先队列，从优先队列里拿出最小点出来，然后看这个节点有没有下一个节点，有的话继续放入优先队列。

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
        if(lists == null || lists.length == 0){
            return null;
        }
        int n = lists.length;
//参数是队列大小，自定义比较器
        Queue<ListNode> heap = new PriorityQueue<ListNode>(n, ListNodeComparator);
        for(int i = 0; i < n; i++){
            if(lists[i] != null){
                heap.add(lists[i]);
            }
        }
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        while(!heap.isEmpty()){
            ListNode head = heap.poll();
            tail.next = head;
            tail = head;
            if(head.next != null){
                heap.add(head.next);
            }
        }
        return dummy.next;

    }
    private Comparator<ListNode> ListNodeComparator = new Comparator<ListNode>() {
        public int compare(ListNode left, ListNode right) {
            return left.val - right.val;
        }
    };
}
```
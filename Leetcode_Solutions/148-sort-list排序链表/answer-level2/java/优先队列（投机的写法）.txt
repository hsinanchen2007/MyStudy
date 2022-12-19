太菜了不会归并排序
```
class Solution {
    public ListNode sortList(ListNode head) {
        ListNode node = head;
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        while(node != null){
            queue.add(node.val);
            node = node.next;
        }
        node = head;
        while(node != null){
            node.val = queue.poll();
            node = node.next;
        }
        return head;
    }
}
```

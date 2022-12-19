```
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode less_header = new ListNode(-1);
        ListNode less = less_header;
        ListNode more_header = new ListNode(-1);
        ListNode more = more_header;
        ListNode node = head;
        while (node != null){
            if (node.val < x) {
                less.next = node;
                less = less.next;
            }else if (node.val >= x) {
                more.next = node;
                more = more.next;
            }
            node = node.next;
        }
        less.next = more_header.next;
        more.next = null; //新链表尾节点需要置为null，否则可能成环
        return less_header.next;
    }
}
```
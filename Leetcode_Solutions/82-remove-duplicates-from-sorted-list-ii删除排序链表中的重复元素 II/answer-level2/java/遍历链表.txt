```
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode node = new ListNode(-1);
        node.next = head;

        ListNode p = node;
        while (p.next != null && p.next.next != null) {
            if (p.next.val == p.next.next.val) {
                int num = p.next.val;
                while (p.next != null && p.next.val == num) {
                    p.next = p.next.next;
                }
            } else {
                p = p.next;
            }
        }
        return node.next;
    }
}
```

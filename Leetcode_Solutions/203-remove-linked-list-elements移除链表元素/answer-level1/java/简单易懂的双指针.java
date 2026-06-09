```java
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode cur = head;
        if(cur == null) return null;
        ListNode next = cur.next;
        if (cur.val == val) return removeElements(next, val);
        while (next != null) {
            while(next != null && next.val == val) {
                next = next.next;
            }
            cur.next = next;
            if (next != null) {
                cur = next;
                next = next.next;
            }
        }
        return head;
    }
}
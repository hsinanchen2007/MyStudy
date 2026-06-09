```
class Solution {
    public int kthToLast(ListNode head, int k) {
        if (head == null) {
            return -1;
        }
        if (head.next == null) {
            return head.val;
        }
        ListNode fast = head;
        ListNode slow = head;
        while (k != 0 && fast != null) {
            k--;
            fast = fast.next;
        }
        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }
        return slow.val;
    }
}
```

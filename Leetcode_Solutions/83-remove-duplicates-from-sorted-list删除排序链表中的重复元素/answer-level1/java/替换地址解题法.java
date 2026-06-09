```
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode result = head;
        while (head != null && head.next != null) {
            ListNode temp = head.next;
            if (temp.val == head.val) {
                head.next = temp.next;
                continue;
            }
            head = head.next;
        }
        return result;
    }
}
```
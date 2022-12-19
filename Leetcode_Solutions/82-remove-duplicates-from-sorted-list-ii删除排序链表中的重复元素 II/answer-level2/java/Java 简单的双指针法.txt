```
class Solution {
   public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) return head;

        ListNode root = new ListNode(-1);
        root.next = head;
        ListNode left = root;
        ListNode right = head;

        boolean isRepeat = false;
        while (right.next != null) {
            if (right.val != right.next.val) {
                if (!isRepeat) {
                    left = left.next;
                    right = right.next;
                } else {
                    left.next = right.next;
                    right = right.next;
                    isRepeat = false;
                }
            } else {
                isRepeat = true;
                right = right.next;
            }
        }
        if (isRepeat) left.next = null;


        return root.next;


    }
}
```

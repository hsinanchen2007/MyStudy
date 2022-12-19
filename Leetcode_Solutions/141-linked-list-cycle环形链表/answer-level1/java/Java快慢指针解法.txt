通过快慢指针，快指针比慢指针先走一步，若有环则最终快慢指针会相遇```

```
public class Solution {
    public boolean hasCycle(ListNode head) {

        ListNode fast = head;
        ListNode slow = head;
        while (slow != null && slow.next != null && fast.next != null && fast.next.next != null) {

            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
}
```


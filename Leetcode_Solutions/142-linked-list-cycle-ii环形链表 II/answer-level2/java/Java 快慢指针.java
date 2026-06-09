```
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head == null) {
            return null;
        }
        ListNode fast = head, slow = head;
        
        while(fast != null && fast.next != null && fast.next.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow) {
                fast = head;
                while (fast != slow) {
                    fast = fast.next;
                    slow = slow.next;
                }
                return fast;
            }
        }

        
        return null;
    }
}
```

快慢指针：fast每次走两步，slow每次走一步。若fast为null，说明无环。若在循环中出现fast=slow，那么说明有环，此时将fast重置到head节点，并变为每次走一步，那么fast和slow的相遇点即为入口节点。
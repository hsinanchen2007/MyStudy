```java []
public class Solution {  
    public ListNode detectCycle(ListNode head) {
        if(head == null || head.next == null){
            return null;
        }
        ListNode fast,slow;
        fast = head;
        slow = head;
        while(fast  != null && fast.next != null)
        {
            fast = fast.next.next;
            slow = slow.next;
            if(fast == slow)   //表示有环
            {
                slow = head;
                while(fast != slow){
                    fast =fast.next;
                    slow = slow.next;
                }
                return slow;
            }
        }
        return null;
    }
}

```
```java []
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head == null || head.next == null){
            return null;
        }

        ListNode slow = head;
        ListNode fast = head.next;
        while(slow != fast){
            if(fast == null || fast.next == null){
                return null;
            }
            slow = slow.next;
            fast = fast.next.next;
        }

        fast = head;
        while(fast != slow.next){  //因为开始时fast提前走了一步，所以要和slow.next比较
            fast = fast.next;
            slow = slow.next;
        }
        return fast;   
    }
}
```

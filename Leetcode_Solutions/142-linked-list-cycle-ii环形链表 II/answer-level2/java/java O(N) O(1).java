floyd cycle detection algorithm
首先快慢指针判圈，在相遇处停下，将一个指针重置并以相同速度遍历 再次相遇的地方即为圈的入口
2(f+a) = f+a+b+a   f=b

```
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head, fast = head;
        boolean hasCycle = false;
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast) {
                hasCycle = true;
                break;
            }
        }
        if(hasCycle){
            fast = head;
            while(fast!=slow){
                fast = fast.next;
                slow = slow.next;
            }
            return slow;
        }
        return null;
    }
}
```

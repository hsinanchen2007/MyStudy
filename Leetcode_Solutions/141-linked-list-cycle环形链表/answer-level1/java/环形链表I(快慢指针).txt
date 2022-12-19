快慢指针：使慢指针与快指针同起点，但不同速率移动，快指针每走两布，慢指针每走一步，相遇即说明有环。‘
伪代码如下：
```
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head==null || head.next==null)return false;
        ListNode fast=head;
        ListNode slow=head;
        while(fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;//fast.next不为空，fast.next.next有意义
            if(fast==null)return false;//同理:保证while里面有意义
            if(fast==slow)return true;
        }
        return false;
        
    }
}
```


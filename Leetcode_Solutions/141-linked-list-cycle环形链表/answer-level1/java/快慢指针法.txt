### 解题思路
此处撰写解题思路
快慢指针法：
快指针每次走两步，慢指针走一步，如果相遇时候都不是null，肯定有环，如果没有相遇时候，快指针已经是null，肯定没有环，慢指针做多走n步，时间复杂度为O(n)，空间复杂度为O(1)
### 代码

```java
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
        if(head==null||head.next==null)
        return false;
        ListNode fast=head.next.next;
        ListNode slow=head.next;
        while(fast!=slow)
        {
            if(fast==null||fast.next==null)
            return false;
            fast=fast.next.next;
            slow=slow.next;
        }
      return true;
    }
}
```
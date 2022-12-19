### 解题思路
操场跑步，跑得快的最后肯定多跑一圈追上跑的慢的。

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
        ListNode slow=head.next;
        ListNode fast=head.next.next;
        while(slow!=null&&fast!=null){
            if(slow==fast)
                return true;

            slow=slow.next;
            if(fast.next==null)
                fast=null;
            else
                fast=fast.next.next;
        }
        return false;
    }
}
```
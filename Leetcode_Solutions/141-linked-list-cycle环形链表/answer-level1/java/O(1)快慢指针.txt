### 解题思路
模拟跑操场，跑的快的人总会有追上跑的慢的人的时候，追上的时候那就说明有环。
### 代码

```java

public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head==null)return false;
        ListNode fast=head.next;
        ListNode slow=head;
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
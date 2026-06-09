### 解题思路
/**
 * 解题思路
 * 1.先定义快慢指针，slow走一步，fast走两步直到相遇，
 * 2.假设头结点test到第一个入环A点处距离为a，到快慢指针相遇处B为a+b
 * 3.则A和B相距b，fast=2（a+b），slow = a+b
 * 4.slow再走a步到A点和 头结点test相同，因此同时出法即可
 */

### 代码

```java
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head == null || head.next == null) return null;
        ListNode slow = head;
        ListNode fast = head;
        ListNode test = head;
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow==fast){
                break;
            }
        }
        if(fast==null || fast.next == null) return null;
        while(slow != test){
            slow = slow.next;
            test = test.next;
        }
        return slow;
    }
}
```
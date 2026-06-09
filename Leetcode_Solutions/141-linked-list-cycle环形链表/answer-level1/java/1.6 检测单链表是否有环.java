### 解题思路
利用快慢指针，如果存在环，则快慢指针会进入环中一直循环，总会碰到一起的。若没有环，则遍历链表的循环会退出，退出说明无环。

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
        if(head==null||head.next==null){
            return false;
        }
        ListNode slow = head;
        ListNode fast = head.next.next;
        while(fast!=null&&fast.next!=null){
            if(slow.next==fast.next)
                return true;
            slow = slow.next;
            fast = fast.next.next; //由于有两个next，所以fast.next一定要有值，否则空指针异常
        }
        return false;
    }
}
```
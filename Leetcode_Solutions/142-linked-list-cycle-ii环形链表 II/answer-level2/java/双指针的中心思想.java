### 解题思路
代码已经很详细啦，至于数学证明部分，可以参考高手的解析...

中心思想： 若存在环，则快慢指针第一次相遇点即为两者走到环入口的距离


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
    public ListNode detectCycle(ListNode head) {
        ListNode faster = head;
        ListNode slower = head;
    
       while(faster != null && faster.next != null){
           faster = faster.next.next;
           slower = slower.next;
if(faster == slower){
   faster = head;
        while(slower != faster){
            slower = slower.next;
            faster = faster.next;
        }
        return faster;
}
         


       }
return null;
        
    }
}
```
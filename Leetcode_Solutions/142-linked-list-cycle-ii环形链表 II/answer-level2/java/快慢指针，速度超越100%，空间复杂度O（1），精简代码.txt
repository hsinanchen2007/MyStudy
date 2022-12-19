### 解题思路
此处撰写解题思路

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
        if(head == null || head.next == null) return null;

        ListNode fast = head.next.next;
        ListNode slow = head.next;

        for(; fast != null && fast.next != null; fast = fast.next.next, slow = slow.next){
            if(slow == fast) {
                for(fast = head; ; fast = fast.next, slow = slow.next) {
                    if(fast == slow) return slow;
                }
            }
        }

        return null;
    }
}
```
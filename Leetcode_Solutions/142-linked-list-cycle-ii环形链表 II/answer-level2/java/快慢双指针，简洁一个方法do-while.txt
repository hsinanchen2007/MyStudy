### 解题思路
和官方思路一样
do-while使代码更加简洁

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
            if(head==null||head.next==null){
                return null;
            }
            ListNode slow = head;
            ListNode fast = head;

            do {
                slow = slow.next;
                fast = fast.next.next;
                if(fast==null||fast.next==null){
                    return null;
                }
            } while (slow!=fast);

            fast = head;
            while(slow!=fast){
                fast = fast.next;
                slow = slow.next;
            }
            return slow;
        }
    }
```
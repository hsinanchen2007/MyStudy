### 解题思路
   先找倒数第n个节点的前驱，使它的next指向要删除结点的next 这样就可把倒数第n个节点删除。

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(n == 0) {
            if(head == null) {
                return null;
            }else {
                return head;
            }
        } 
        ListNode slow = head;
        ListNode fast = head;
        for(int i = 0; i < n-1; i++) {
            fast = fast.next;
        }
        while(fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        if(slow == head) {
            return head.next;
        }
        ListNode prev = head;
        while(prev.next != slow) {
            prev = prev.next;
        }
        prev.next = slow.next;
        return head;

    }
}
```
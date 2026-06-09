### 解题思路

一：快慢指针确定是否存在环
二：通过环内节点确定入环节点

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
 * f = 2s;  f = s + nb;
 * f = 2nb; s = nb;
*  k = a + nb;
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head == null){
            return null;
        }

        ListNode cycleNode = getCycleNode(head);
        if(cycleNode == null){
            return null;
        }

        ListNode h1 = head;
        ListNode h2 = cycleNode;
        while(h1!=h2){
            h1 = h1.next;
            h2 = h2.next;
        }
        return h1;
    }
    private ListNode getCycleNode(ListNode head){
        ListNode slow = head;
        ListNode fast = head;
        while(fast != null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;
            if(fast==slow){
                return slow;
            }
        }
        return null;
    }
}
```
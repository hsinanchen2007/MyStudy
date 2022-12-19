### 解题思路


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
public boolean isPalindrome(ListNode head){
        if(head == null || head.next == null)
            return true;
        ListNode fast = head;
        ListNode slow = head;
        ListNode prev = null;
        while(fast != null && fast.next != null ){
            fast = fast.next.next;
            ListNode nextNode = slow.next;
            slow.next = prev;
            prev = slow;
            slow = nextNode;
        }
        if(fast != null){
            slow = slow.next;
        }
        while(prev != null){
            if(prev.val != slow.val)
                return false;
            prev = prev.next;
            slow = slow.next;
        }
        return true;

    }
}
```